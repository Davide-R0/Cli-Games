#include "ship.h"
#include "constant.h"
#include <string.h>

namespace btshp {
    
     std::string ship::ship_name[] = {
        "ship1",
        "ship2",
        "ship3"
    };

    ship::ship(int type) : ship_type{type}{
        ship_dim.y = ship_form[ship_type].size();
        ship_dim.x = ship_form[ship_type][0].size();
        state = false;
        num_box = 0;
    }

    ship::~ship(){
    }
    
    void ship::setRenderSettings(WINDOW* window, int x, int y) {
        window = win;
        ship_dim.x_rend = x;
        ship_dim.y_rend = y;
    }

    bool ship::renderIndex() {
        char character[4];
        if (!state) {
            strcpy(character, ship_char); 
        }else {
            strcpy(character, ship_sink_char);
        }

        for (int i = 0; i<ship_dim.y; i++) {
            for (int j = 0; j<ship_dim.x; j++) {
                if (ship_form[ship_type][i][j] == '1') {
                    mvwprintw(win, ship_dim.x_rend-j, ship_dim.y_rend-i, character);
                    num_box ++;
                }
            }
        }
        wrefresh(win);
        return true;
    }

    bool ship::print(int* tab[], int x, int y, int y_dim) {
        ship_dim.x_rend = x;
        ship_dim.y_rend = y;
        for (int i = 0; i<ship_dim.y; i++) {
            for (int j = 0; j<ship_dim.x; j++) {
                if (ship_form[ship_type][i][j] == '1' && *tab[x-j * y_dim * y-i] != 0) { //check if there is a sovrapposition with other ships 
                    *tab[x-j * y_dim * y-i] = 1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    void ship::changeStatus() {
        state = true;
    }
    
    bool ship::checkAttackSink(int x, int y) {
        if (ship_form[ship_type][ship_dim.x_rend-x][ship_dim.y_rend-y] == '1') {
            num_box --;
            if (num_box <= 0) changeStatus();
            return true;
        } else {
            return false;
        }
    }

}
