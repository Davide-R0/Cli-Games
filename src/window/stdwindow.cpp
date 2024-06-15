#include "stdwindow.h"

attribute_info stdwin;

void init_window(bool key) {
    //add the logger message
    // Set locale attributes (including encoding) from the environment
    //usefull?
    if (!setlocale(LC_ALL, "C")) printf("Failed to set locale attributes from environment");
    
    // init screen and sets up screen
    if (!initscr()) printf("Failed to initialize ncurses");
    
    //ricontrollare:
    cbreak();
    //diable automatc printing
    noecho();
    //enable keypad user
    keypad(stdscr, key);
    nonl();               // Get return key
    timeout(0);           // Non-blocking input
    curs_set(0);          // Hide real cursor
    intrflush(stdscr, 0); // Avoid potential graphical issues flush
    leaveok(stdscr, 1);   // no cursor motion
    
    //refresh window and set max values
    refreshInfo();
    refresh();

    //printf("Stdwindow initialized!\n");
}


void refreshInfo() {
    stdwin.x = 0;
    stdwin.y = 0;
    getmaxyx(stdscr, stdwin.y_rend, stdwin.x_rend);
}


void destroy_window() {
    endwin();
    //change to the standard error log
    printf("Stdwindow destroied!\n");
}
