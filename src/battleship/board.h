#ifndef BOARD_H
#define BOARD_H

//ncurses
#include <ncurses.h>

//std 
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib> //random number
//#include <map>

//sources
#include "constant.h"
#include "ship.h"


namespace btshp {
    
    class board {
        public:
            //board dimension, number of ships, type of board:
            board(int dim_x, int dim_y, int n_sh, bool AI_mode);
            ~board();
            
            //render all the board
            //add position
            bool render() const;    //render on std screen window 
            bool render(WINDOW** win) const;    //render on win window
            
            //attack a block
            //return false if place alredy hit or if there is an error in the initialization of the board
            bool attack(WINDOW** win, int x, int y) const;

        private:
            const int n_ships;
            
            const bool ai_mode;
            
            int x_dim, y_dim;

            //vector ships 
            std::vector<ship*> ships;
            
            //legend:
            //0 = water not see 
            //1 = ship not see 
            //2 = water see
            //>3 = ship see
            int* render_table;

            bool init_ships();
    };

}

#endif 
