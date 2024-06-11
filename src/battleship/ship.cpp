#include "ship.h"

namespace btshp {
    //use enum???
    //used in case of naming ships
    //std::unordered_map<std::string, int> ship_type = {
    //    {"ship1", 1},
    //    {"ship2", 2},
    //    {"ship3", 3}
    //};

    
    std::string ship::ship_name[] = {
        "ship1",
        "ship2",
        "ship3"
    };

    //TODO: come salvare i punti da stsaampare per ogni barca??
   
    
    ship::ship(int type) : ship_type(type){
    
    }

    
    bool ship::render(int x, int y) const {
        
        refresh();
        return true;
    }

    bool ship::render(WINDOW** win, int x, int y) const {
        
        wrefresh(*win);
        return true;
    }
}
