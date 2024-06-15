//STD

//sources
//#include "battleship/battleship.h"
#include "window/window.h"
#include "window/stdwindow.h"

#include "norMode.h"
#include "insMode.h"
#include "cmdMode.h"

//template log managing
#ifndef NDEBUG
//custom log message
#else
//else
#endif

int main() {
    //initialize stdwindow 
    //...
    
    
    //initialize window 
    //something like: startWindow();
    
    bool should_close = false;

    char current_mode = 'n'; //possible modes:
                             // - n: normal, window selected 
                             // - i: insert, insert text
                             // - c: command, inserto command in the command windo 

    char ch = 'n';
    //main render loop
    while (!should_close) {
        ch = getch();
        
        //chose the modes
        switch (current_mode) {
            case 'n':
            default:
                normalMode(ch, &current_mode);
                break;
            case 'i':
                insertMode(ch, &current_mode);
                break;
            case 'c':
                commandMode(ch, &current_mode, &should_close);
                break;
        };
    }
    
    //end stdwindow
    //...

    return 0;
}
