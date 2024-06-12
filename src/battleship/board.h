#ifndef BOARD_H
#define BOARD_H

//ncurses
#include <ncurses.h>

//std 
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib> //random number

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
            board(WINDOW* window, attribute_info info, int n_sh);
            ~board();
            
            //render all the board
            //add position
            void setRenderSettings(WINDOW* window, int x, int y);
            bool renderBoard() const;    //render on win window 

            //attack a block
            //return false if place alredy hit or if there is an error in the initialization of the board
            bool attack(int x, int y);  //change return state in ship_return_state 
            
            int getRemainingShips() const { return ships.size() - sinked_ships.size(); };
            attribute_info getShipInfo() const { return board_dim; };

        private:
            const int n_ships;
            attribute_info board_dim;
            WINDOW* win;

            //vector ships 
            std::vector<ship*> ships;
            std::vector<int> sinked_ships;   //indecies of sinked ship 

            //legend:
            //0 = water not see 
            //1 = ship not see 
            //2 = water see
            //>3 = ship see
            int* render_table;
            

            bool init_ships();
            bool init_render_table();
    };

}

#endif 
