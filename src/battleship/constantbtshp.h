#ifndef CONSTANTBTSHP_H
#define CONSTANTBTSHP_H

#include <vector>
#include <string>
#include "../constant.h"

namespace btshp {


    const char ship_char[4] = "x";
    const char ship_sink_char[4] = "::";
    const char water_char[4] = "~";
    const char notsee_char[4] = "*";

    

#define MAX_SHIP 3

    //for uft-8 character see:
    //https://www.w3schools.com/charsets/ref_utf_block.asp
    
    //NOTE:
    //  -change font size for vertical alignment, two full vertical block shouldent have spaces between
    //  -deactivate "autohint" if necessary (try with and without)

    //box characters:
    //echo "╭──╮" && echo "│  │" && echo "╰──╯" 
    //echo "█▉█▉█▉█▉█▉▓▓▒▒░░" && echo "█▉█▉█▉█▉█▉▓▓▒▒░░"
    //echo "█▉█▉╳╳█▉█▉" && echo "█▉█▉╳╳╳╳█▉"
    //echo -e "┏━━┳━━┳━━┓ \n┃██┃██┃██┃ \n┣━━╋━━╋━━┫ \n┃██┃██┃██┃ \n┗━━┻━━┻━━┛"
    //echo -e "┏━━┳━━┳━━┓ \n┃██┃██┃██┃ \n┣━━╋━━╋━━┫ \n┃\033[0;36m▓▓\033[0m┃\033[0;33m▒▒\033[0m┃\033[0;35m░░\033[0m┃ \n┣━━╋━━╋━━┫ \n┃  ┃  ┃██┃ \n┗━━┻━━┻━━┛"
    //echo -e "┏━━━━┳━━━━┳━━━━┓ \n┃████┃████┃████┃ \n┃████┃████┃████┃ \n┣━━━━╋━━━━╋━━━━┫ \n┃████┃████┃████┃ \n┃████┃████┃████┃ \n┗━━━━┻━━━━┻━━━━┛"
    //echo -e "┏━━━━━━┳━━━━━━┳━━━━━━┓ \n┃██████┃██████┃██████┃\n┃██████┃██████┃██████┃ \n┃██████┃██████┃██████┃ \n┣━━━━━━╋━━━━━━╋━━━━━━┫ \n┃██████┃██████┃██████┃ \n┃██████┃██████┃██████┃ \n┃██████┃██████┃██████┃\n┗━━━━━━┻━━━━━━┻━━━━━━┛"
    //echo -e "\n██████┃██████┃██████\n██████┃██████┃██████ \n██████┃██████┃██████ \n━━━━━━╋━━━━━━╋━━━━━━ \n██████┃██████┃██████ \n██████┃██████┃██████ \n██████┃██████┃██████"
    //eventually use "┝" "┥" "┰" "┸" on the borders



    //use "Braille" uft8 character for loading characters
    
    //Note: add ship in a rectangular shape with 1 and 0, no check if there is an error
    const std::vector<std::vector<std::string>> ship_form = {
        {
            {"0001100"},
            {"1111111"},
            {"0111110"}
        },
        {
            {"00100"},
            {"11111"},
            {"01110"}
        },
        {
            {"111111"},
            {"011110"}
        }
    };

}

#endif
