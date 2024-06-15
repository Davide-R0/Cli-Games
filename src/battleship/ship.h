#ifndef SHIP_H
#define SHIP_H

//ncurses
#include <ncurses.h>

//std
#include <vector>
#include <unordered_map> 
#include <string>

//sources
#include "constantbtshp.h"

namespace btshp { 
    
    
    class ship {
        public:
            //x,y: top left corner of ship rendering
            //constructor call only form board 
            ship(int type);
            ~ship();
            
            //w, y: top left corner of ship rendering
            //change window and position of rendering
            void setRenderSettings(WINDOW* window, int x, int y);

            //render ship image
            //note: the position given is referred to the edge top left
            bool renderIndex();    //render on win window
            
            //pint on the table of the board
            //return false if the ship overlap with something else
            bool print(int* tab[], int x, int y, int y_dim);

            int getType() const { return ship_type; };
            std::string getName() const { return ship_name[ship_type]; };
            attribute_info getShipInfo() const { return ship_dim; };
            
            bool checkAttackSink(int x, int y);
            
            bool getStatus() const { return state; };
            
        private:
            const int ship_type;
            int num_box; //number of box checked for each ship
            attribute_info ship_dim;
            static std::string ship_name[MAX_SHIP];

            //render settings
            WINDOW* win;
            bool state = false; //if ship is sink
            
            //cange status in the visualization render() function
            //note that after changing state is necessary recall render() function 
            void changeStatus();
                       
    };
    

}


#endif 
