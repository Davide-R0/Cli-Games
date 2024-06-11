#ifndef SHIP_H
#define SHIP_H

//ncurses
#include <ncurses.h>

//std
#include <vector>
#include <unordered_map> 
#include <string>

//sources
#include "constant.h"

namespace btshp { 
    
    struct dim_ships {
        int x, y;
    };
    
    class ship {
        public:
            ship(int type);
            ~ship();
           
            //render ship image
            //note: the position given is referred to the edge top left
            bool render(int x, int y) const;    //render on std screen window 
            bool render(WINDOW** win, int x, int y) const;    //render on win window
            
            //pint on the table of the board
            bool print(int* tab[], int x, int y, int y_dim) const;

            int getType() const { return ship_type; };
            std::string getName() const { return ship_name[ship_type]; };
            dim_ships getDimension() const { return ship_dim; };

            
        private:
            const int ship_type;
            dim_ships ship_dim;
            static std::string ship_name[MAX_SHIP];
            
    };
    

}


#endif 
