#include "ship.h"

namespace btshp {
    
     std::string ship::ship_name[] = {
        "ship1",
        "ship2",
        "ship3"
    };

    ship::ship(int type) : ship_type(type){
        ship_dim.y = ship_form[ship_type].size();
        ship_dim.x = ship_form[ship_type][0].size(); 
    }
    

    
    bool ship::render(int x, int y) const {
        for (int i = 0; i<ship_dim.y; i++) {
            for (int j = 0; j<ship_dim.x; j++) {
                if (ship_form[ship_type][i][j] == '1') mvprintw(x-j, y-i, ship_char);
            }
        }
        refresh();
        return true;
    }

    bool ship::render(WINDOW** win, int x, int y) const {
        for (int i = 0; i<ship_dim.y; i++) {
            for (int j = 0; j<ship_dim.x; j++) {
                if (ship_form[ship_type][i][j] == '1') mvwprintw(*win, x-j, y-i, ship_char);
            }
        }
        wrefresh(*win);
        return true;
    }

    bool ship::print(int* tab[], int x, int y, int y_dim) const {
        for (int i = 0; i<ship_dim.y; i++) {
            for (int j = 0; j<ship_dim.x; j++) {
                if (ship_form[ship_type][i][j] == '1') *tab[x-j * y_dim * y-i] = true;
            }
        }
        return true;
    }

}
