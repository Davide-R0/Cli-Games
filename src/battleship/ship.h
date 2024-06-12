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
        int x_tab, y_tab;
    };
    
    class ship {
        public:
            ship(int type);
            ~ship();
            
            void setRenderSettings(WINDOW** win, int x, int y);

            //render ship image
            //note: the position given is referred to the edge top left
            bool renderIndex();    //render on win window
            
            //pint on the table of the board
            //return false if the ship overlap with something else
            bool print(int* tab[], int x, int y, int y_dim);

            int getType() const { return ship_type; };
            std::string getName() const { return ship_name[ship_type]; };
            dim_ships getDimension() const { return ship_dim; };
            
            bool checkAttack(int x, int y);
            
            bool getStatus() const { return state; };
            
        private:
            const int ship_type;
            int num_box; //numbero of box checked for each ship
            dim_ships ship_dim;
            static std::string ship_name[MAX_SHIP];

            //render settings
            int x_rend, y_rend;
            WINDOW** ship_window;
            bool state = false; //if ship is sink
            
            //cange status in the visualization render() function
            //note that after changing state is necessary recall render() function 
            void changeStatus();
                       
    };
    

}


#endif 
