#ifndef INSERT_WIN_H
#define INSERT_WIN_H
//STD

//sources
#include "window.h"

class insert_win : public window{
    public:
        insert_win();
        ~insert_win();

        void insertMode();
        
        bool getMultilineMode() const { return m_multiline_mod; };
        void setMultilineMode(bool state);      //è meglio farlo ciclico? che una volta chiamata cambia lo stato?

    private:
        bool m_multiline_mod;
};

#endif 
