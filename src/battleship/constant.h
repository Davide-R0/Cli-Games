#ifndef CONSTANT_H
#define CONSTANT_H

#include <vector>
#include <string>

namespace btshp {


    const char ship_char[4] = "x";
    const char ship_sink_char[4] = "::";
    const char water_char[4] = "~";
    const char notsee_char[4] = "*";

    //struct for the attribute info:
    //position on window, dimension
    struct attribute_info {
        int x, y;
        int x_rend, y_rend;
    };

#define MAX_SHIP 3

    //for uft-8 character see:
    //https://www.w3schools.com/charsets/ref_utf_block.asp
    
    //box characters:
    //echo "╭──╮" && echo "│  │" && echo "╰──╯"
    //echo "█▉█▉█▉█▉█▉▓▓▒▒░░" && echo "█▉█▉█▉█▉█▉▓▓▒▒░░"
    //echo "█▉█▉╳╳█▉█▉" && echo "█▉█▉╳╳╳╳█▉"

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
