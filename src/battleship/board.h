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
    struct ship_return_state {
        bool status;        //status returning, if hit a previousli hitten spot
        bool sink;          //if a ship is sinked (false as default)
        ship* ship_sink;    //wich whip is sinked (nullptr as default)
    };

    class board {
        public:
            //board dimension, number of ships, type of board:
            board(int dim_x, int dim_y, int n_sh, bool AI_mode);
            ~board();
            
            //render all the board
            //add position
            bool render(WINDOW** win) const;    //render on win window
            
            //attack a block
            //return false if place alredy hit or if there is an error in the initialization of the board
            bool attack(WINDOW** win, int x, int y) const;  //change return state in ship_return_state 
            
            int getRemainingShips() const { return ships.size(); };
            

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
