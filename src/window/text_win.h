#ifndef TEXT_WIN_H
#define TEXT_WIN_H

//STD

//assets
#include "window.h"

class text_win : public window {
    public:
        text_win();
        ~text_win();

        void addLineToBuffer(std::string buffer, int index = -1);
        void addToBuffer(std::string buffer, int line, int col);    //add text to buffer 
        void changeBuffer(std::string buffer, int line, int col);   //replace text to buffer 
        
        //all the color text and background things...
        
    private:

};

#endif 
