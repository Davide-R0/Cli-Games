#include "norMode.h"
#include "cmdMode.h"
#include <ncurses.h>

void normalMode(char ch, char* current_mode){
    //hash map to search the command - function ecc...
    
    //at the moment:
    //basic movement to change between window
    switch (ch) {
        case 'j':
        case 's':
            break;

        case 'k':
        case 'w':
            break;

        case 'l':
        case 'd':
        case KEY_ENTER:
            break;
        
        case 'h':
        case 'a':
            break;

        case ':':
            *current_mode = 'c';
            break;
    };
}
