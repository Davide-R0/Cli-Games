#ifndef WINDOW_H
#define WINDOW_H 

//STD
#include <ncurses.h>
#include <string>
#include <vector>

//assets
#include "../constant.h"

class window {
    public:
        window(window_info n_info, std::string name, WINDOW* orig_w = nullptr);
        virtual ~window();
        
        //window managing 
        void setWindowInfo(window_info n_info);
        window_info getWindowInfo() const { return m_info_w; };
        const WINDOW* getWindow() const { return m_wind; };
        virtual int SgetNumWindows() const { return s_num_w; };
        
        //general settings
        window_modes getModes() const { return m_modes; };
        void setModes(window_modes modes);  //this call the function needed:
        //each of this functions call the renderText() function to riformatting the text to print
        void setBorder(chtype* ls, chtype* rs, chtype* ts, chtype* bs, chtype* tl, chtype* tr, chtype* bl, chtype* br); 
        /*  ls - left side,
         *  rs - right side,
         *  ts - top side,
         *  bs - bottom side,
         *  tl - top left-hand corner,
         *  tr - top right-hand corner,
         *  bl - bottom left-hand corner,
         *  br - bottom right-hand corner.
        */

        //rendering
        //è necessario???
        void refresh();
        //{ wrefresh(m_wind); };
        //nel refresh bisogna controllare:
        //se la finestra è stata ridimensionata ...???
        //se sono stati modificati dei "modes" ...
        //se è stata aggiunta una cornice ...
        //...

        //buffers managing
        std::vector<std::string> getBuffer() const { return m_text_buffer; };
        
    private:
        std::string m_name_w;
        WINDOW* m_wind; //use unique_ptr?? no perchè non si potrebbero creare subwindow ??
        WINDOW* m_base_wind = nullptr;  //come passare il valore in modo che eliminando la finestra base la derivate diventi base?
        window_info m_info_w;
        static int s_num_w;         //non inizializato !!!!!
        
        window_modes m_modes;

        std::vector<std::string> m_text_buffer;
        
        //all this function print the text in the right format on the window buffer, before refreshing
        void renderAll();
        void renderLineText(std::string text, int line, int col);
        void useLineNumber(); //necessario o semplicemente basta implementarlo in un'altra finzione?? (come in renderText)
        void useScroll();

        //this two cannot be used at the same time
        void useAutoNewLine(); //necessario o semplicemente basta implementarlo in un'altra finzione?? (come in renderText)
        void useAutoResize();
        
};
#endif 
