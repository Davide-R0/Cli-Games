#include "board.h"
#include "constant.h"
#include "ship.h"

namespace btshp {
    board::board(int dim_x, int dim_y, int n_sh, bool AI_mode) : n_ships{n_sh}, ai_mode{AI_mode} {
        if (!init_ships()) std::cerr << "Error initializing ships\n";
        
        if (dim_x>0 && dim_y>0) {
            x_dim = dim_x;
            y_dim = dim_y;
            render_table = new int[x_dim*y_dim];
            for (int i = 0; x_dim*y_dim; i++) render_table[i] = 2;
            /*
            int *ary = new int[sizeX*sizeY];

            // ary[i][j] is then rewritten as
            ary[i*sizeY+j]
            */
        } else {
            std::cerr << "Error board\n";
        }
    }

    bool board::init_ships() {
        if (n_ships > 0) {
            for (int i = 0; i < n_ships; i++) {
                //rand() % #; //form 0 to #-1

                //ai_mode 
                ship* s = new ship(rand() % MAX_SHIP);
                
                //save in table
                s->print(&render_table, rand() % x_dim, rand() % y_dim, y_dim);        //funziona????
                
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
    
    bool board::render() const {
        for (int i = 0; i<y_dim; i++) {
            for (int j = 0; j<x_dim; j++) {
                switch (render_table[i*y_dim+j]) {
                    //not see by user
                    case 1:
                    case 2:
                    default:
                        mvprintw(j, i, notsee_char);
                        break;
                    
                    //water
                    case 3:
                        mvprintw(j, i, water_char);
                        break;
                    
                    //ship 
                    case 4:
                        mvprintw(j, i, ship_char);
                        break;
                };
                    
            }
        }
        refresh();
        return true;
    }

    bool board::render(WINDOW** win) const {
        for (int i = 0; i<y_dim; i++) {
            for (int j = 0; j<x_dim; j++) {
                switch (render_table[i*y_dim+j]) {
                    //not see by user
                    case 0:
                    case 1:
                    default:
                        mvwprintw(*win, j, i, notsee_char);
                        break;
                    
                    //water
                    case 2:
                        mvwprintw(*win, j, i, water_char);
                        break;
                    
                    //ship 
                    case 3:
                        mvwprintw(*win, j, i, ship_char);
                        break;
                };
                    
            }
        }
        wrefresh(*win);
        return true;
    }


    bool board::attack(WINDOW** win, int x, int y) const {
        switch (render_table[x*y_dim+y]) {
            case 0:
                render_table[x*y_dim+y] = 2;
                mvwprintw(*win, x, y, water_char);
                wrefresh(*win);
                return true;
                break;      //non è necessario il break dopo il return??
            case 1:
                render_table[x*y_dim+y] = 3;
                mvwprintw(*win, x, y, water_char);
                wrefresh(*win);
                return true;
                break;
            case 2:
            case 3:
            default:
                return false;
                break;
        };

        return false;
    }


    board::~board(){
        //useless??
        ships.clear();
    }
}
