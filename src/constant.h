#ifndef CONSTANT_H 
#define CONSTANT_H
//not already clear what this file should be

struct window_info {
    int x_pos, y_pos;   //position top left corner to respect base window
    int x_dim, y_dim;
};

struct window_modes {
    bool border_mod;
    bool line_number_mod;
    bool scroll_mod;
    bool auto_new_line_mod;
    bool auto_resize_mod;   //auto_resize and auto_new_line cannot be setted at the same time

};

#endif 
