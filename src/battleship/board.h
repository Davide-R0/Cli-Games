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
#include "ship.h"

namespace btshp {
    
    class board {
        public:
            //board dimension, number of ships, type of board:
            board(int dim_x, int dim_y, int n_sh, bool AI_mode);
            ~board();
            
            //resize the board, ADD various check
            //TODO: aggiungere unisgned???
            bool resize(int dim_x, int dim_y);
            
            

            //render board status
            //add position
            bool render(int x, int y) const;    //render on std screen window 
            bool render(WINDOW** win, int x, int y) const;    //render on win window
            
            //attack a block
            bool attack(const std::string target) const;

            //
        private:
            const int n_ships;
            int x_dim, y_dim;
            const bool ai_mode;
            //ship* ships;
            //vector ships 
            std::vector<ship*> ships;
            //typedef std::map<ship*, int> ships;
            
            bool init_ships();
    };

}

#endif 
