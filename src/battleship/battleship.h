#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "board_ai.h"
#include "board_player.h"
#include "constantbtshp.h"

namespace btshp {
void battleship();

void initBattleship();

//insert inisde global render loop
void loopBattleship();

void endBattleship();

};

#endif 
