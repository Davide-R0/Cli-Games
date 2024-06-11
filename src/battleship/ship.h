#ifndef SHIP_H
#define SHIP_H

//ncurses
#include <ncurses.h>

//std
#include <vector>
#include <unordered_map> 
#include <string>

namespace btshp { 
    #define MAX_SHIP 3

    
    struct dim_ships {
        int x, y;
    };

    class ship {
        public:
            ship(int type);
            ~ship();
           
            //render ship image
            bool render(int x, int y) const;    //render on std screen window 
            bool render(WINDOW** win, int x, int y) const;    //render on win window
            
            int getType() const { return ship_type; };
            std::string getName() const { return ship_name[ship_type]; };
            dim_ships getDimension() const;


            
        private:
            const int ship_type;
            static std::string ship_name[MAX_SHIP];

    };
    

}


#endif 
