#ifndef SELECT_WIN_H
#define SELECT_WIN_H
//STD

//assets
#include "text_win.h"

class select_win : public text_win {
    public:
        select_win();
        ~select_win();
        
        //the index of selection is in base of the line of the text
        //enter in a loop for selection
        int getSelection() const;

        void setBcColorSelection();
        //vairable getBcColorSelection() const;

    private:
        //variable backgroung color m_bc_color_sel = default;
};

#endif 
