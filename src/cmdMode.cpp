#include "cmdMode.h"

#ifndef CTRL
#define CTRL(c) ((c) & 037)
#endif

void commandMode(char ch, char* current_mode, bool* should_exit) {
    //....
    
    //dovrebbe andare in insert mode e inserire dopo il command che si vuole...

    //momentaneamente:
    switch (ch) {
        case KEY_EXIT:
        case CTRL('c'):  //funziona??
            *current_mode = 'n';
            break;

        case 'q':
            *should_exit = true;

    }
}
