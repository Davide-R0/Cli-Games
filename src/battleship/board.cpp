#include "board.h"

namespace btshp {
    board::board(int dim_x, int dim_y, int n_sh, bool AI_mode) : n_ships{n_sh}, ai_mode{AI_mode} {
        if (!resize(dim_x, dim_y)) std::cerr << "Error resizing\n";
        if (!init_ships()) std::cerr << "Error initializing ships\n";
    }

    bool board::resize(int dim_x, int dim_y) {
        //TODO: add checks ...
        if (dim_x>0 && dim_y>0) {
            x_dim = dim_x;
            y_dim = dim_y;
            return true;
        } else {
            return false;
        }
    }

    bool board::init_ships() {
        if (n_ships > 0) {
            for (int i = 0; i < n_ships; i++) {
                //rand() % #; //form 0 to #-1
                ship* s = new ship(i);
                //settings
                
                /* remove elements:
                int elementToRemove = 5; 
  
                // Remove the element using erase function and iterators 
                auto it = std::find(myVector.begin(), myVector.end(), 
                        elementToRemove); 
  
                // If element is found found, erase it 
                if (it != myVector.end()) { 
                    myVector.erase(it); 
                }
                */

                ships.push_back(s); 
                //serve o viene eliminito automaticamente
                delete s;
            }

            return true;
        } else {
            //....
            return false;
        }
    }
    
    bool board::render(int x, int y) const {
        
        refresh();
        return true;
    }

    bool board::render(WINDOW** win, int x, int y) const {
        
        wrefresh(*win);
        return true;
    }


    board::~board(){
        //useless??
        ships.clear();
    }
}
