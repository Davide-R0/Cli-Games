#ifndef STDWINDOW_H  
#define STDWINDOW_H 

//STD 
#include <ncurses.h>
//#include <stdio.h>
#include <clocale>

//sources
#include "../constant.h"


void init_window(bool key);
      
//Manually managed things:
//  refresh() window
//  getch()
//  border() settings
        
//read window dimension
void refreshInfo();

void destroy_window();


#endif 
