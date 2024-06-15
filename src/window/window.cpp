#include "window.h"
#include <ncurses.h>

window::window(window_info n_info, std::string name, WINDOW* orig_w) : m_name_w{name}, m_info_w{n_info} {
    //add various check
    if (orig_w == nullptr) {
        m_wind = newwin(m_info_w.x_pos, m_info_w.y_pos, m_info_w.x_dim, m_info_w.y_dim);
    } else { //add checks if is a WINDOW* valid pointer??
        m_wind = subwin(orig_w, m_info_w.x_pos, m_info_w.y_pos, m_info_w.x_dim, m_info_w.y_dim);
        m_base_wind = orig_w;
    }
    s_num_w++;
    //add message log
}

window::~window() {
    s_num_w--;
    delwin(m_wind);
    m_wind = nullptr;
    //add message log
}

void window::setWindowInfo(window_info n_info) {
    //add checks for resizing or partial movement...
    m_info_w = n_info;
    
    if (m_base_wind == nullptr) {
        mvwin(m_wind, m_info_w.x_pos, m_info_w.y_pos);
    } else {
        mvderwin(m_wind, m_info_w.x_pos, m_info_w.y_pos);
        //constrain max dim for derived window
        if (m_info_w.x_dim + m_info_w.x_pos >= getmaxx(m_base_wind)) 
            m_info_w.x_dim = getmaxx(m_base_wind) - m_info_w.x_pos; //add message log??
        if (m_info_w.y_dim + m_info_w.y_pos >= getmaxy(m_base_wind)) 
            m_info_w.y_dim = getmaxy(m_base_wind) - m_info_w.y_pos; //add message log??
    }
    wresize(m_wind, m_info_w.x_dim, m_info_w.y_dim);
}

void window::setModes(window_modes modes) {
    //NOTE: add various checks
    //  -auto_new_line_mod and auto_resize_mod cannot be activate at the same time
    m_modes = modes;
}

void window::refresh() {
    //refresh the window and check if necessary rerendering
    // no: renderAll(); ???
    wrefresh(m_wind);
}

void window::renderAll() {
    //check which line are to update
    int start_line = 0;
    if (m_modes.border_mod) start_line = 1;
    
    //add condition if scrolling is activated
    for (size_t i = start_line; i<m_text_buffer.size()- start_line; i++) {
        renderLineText(m_text_buffer[i], i, 0);
    }

}

//render a single line of the buffer
void window::renderLineText(std::string render_text, int line, int col) {
    if (m_modes.auto_resize_mod && !m_modes.auto_new_line_mod){
        if (m_info_w.y_dim < render_text.size()) m_info_w.y_dim = render_text.size();
    }
    
    int y_min = col;
    int y_max = m_info_w.y_dim;

    if (m_modes.border_mod) {
        y_min++;  
        y_max--;
    }
    if (m_modes.line_number_mod) {
        y_min++;
    }
    
    mvwprintw(m_wind, line, y_min, "%s", render_text.substr(0, y_max-y_min).c_str());
    
    if (m_modes.auto_new_line_mod) {
        //print the other part of the string...
        //farlo ricorsivo con questa stessa funzione, (anche se è pricoloso)
        renderLineText(render_text.substr(y_max-y_min, render_text.size()), line+1, col);
        //remove the eventual numbers of line
    }
}
