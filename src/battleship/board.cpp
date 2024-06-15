#include "board.h"
#include "constantbtshp.h"
#include "ship.h"

namespace btshp {
    board::board(WINDOW* window, attribute_info info, int n_sh) : win{window}, board_dim{info}, n_ships{n_sh} {
        if (!init_ships()) std::cerr << "Error initializing ships\n";
        
        if (board_dim.y>0 && board_dim.x>0) {
            //initialize render table 
            init_render_table();
                        //initialize ships 
            init_ships();
            
        } else {
            std::cerr << "Error board construction\n";
        }
    }
    
    bool board::init_render_table(){
        render_table = new int[board_dim.x*board_dim.y];
        for (int i = 0; board_dim.x*board_dim.y; i++) render_table[i] = 0;
        /*
        int *ary = new int[sizeX*sizeY];
        // ary[i][j] is then rewritten as
        ary[i*sizeY+j]
        */
        return true;
    }

    bool board::init_ships() {
        if (n_ships > 0) {
            for (int i = 0; i < n_ships; i++) {
                //rand() % #; //form 0 to #-1

                //ai_mode 
                ship* s = new ship(rand() % MAX_SHIP);
                
                //save in table
                while (!s->print(&render_table, rand() % board_dim.x, rand() % board_dim.y, board_dim.y)){
                }   //at the moment reiterate until got one
                    //may be unefficent

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
    
    void board::setRenderSettings(WINDOW* window, int x, int y){
        window = win;
        board_dim.x_rend = x;
        board_dim.y_rend = y;
    }

    bool board::renderBoard() const {
        for (int i = 0; i<board_dim.y; i++) {
            for (int j = 0; j<board_dim.x; j++) {
                switch (render_table[i*board_dim.y+j]) {
                    //not see by user
                    case 0:
                    case 1:
                    default:
                        mvwprintw(win, j, i, notsee_char);
                        break;
                    
                    //water
                    case 2:
                        mvwprintw(win, j, i, water_char);
                        break;
                    
                    //ship 
                    case 3:
                        mvwprintw(win, j, i, ship_char);
                        break;
                };
                    
            }
        }
        wrefresh(win);
        return true;
    }


    bool board::attack(int x, int y) {
        switch (render_table[x*board_dim.y+y]) {
            case 0:
                render_table[x*board_dim.y+y] = 2;
                mvwprintw(win, x, y, water_char);
                wrefresh(win);
                return true;
            case 1:
                render_table[x*board_dim.y+y] = 3;
                
                //probably not very efficient
                //check which ship is touched
                for (int i = 0; i < ships.size(); i++) {
                   if (ships[i]->checkAttackSink(x, y)) {
                       sinked_ships.push_back(i);
                   }
                }
                mvwprintw(win, x, y, ship_char);
                wrefresh(win);
                return true;
            case 2:
            case 3:
            default:
                return false;
        };

        return false;
    }


    board::~board(){
        //useless??
        ships.clear();
    }
}
