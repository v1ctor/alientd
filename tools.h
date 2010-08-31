#ifndef TOOLS_H
#define TOOLS_H


#include "SDL.h"
#include "go.h"

const int range = 60;
static int field[10][10] = {
				 {0,1,1,1,1,1,1,0,0,1},
				 {0,1,0,0,0,0,1,1,1,1},
				 {0,1,0,0,0,0,0,0,0,0},
				 {0,1,0,0,1,1,1,1,1,1},
				 {0,1,0,0,1,0,0,0,0,1},
				 {0,1,1,1,1,0,0,0,0,1},
				 {0,0,0,0,0,0,1,1,1,1},
				 {0,0,1,1,1,0,1,0,0,0},
				 {0,0,1,0,1,0,1,0,0,0},
				 {0,0,1,0,1,1,1,0,0,0}
	            };

void InitImages();
void DrawIMG(int x, int y, SDL_Surface *img, SDL_Surface* screen);
#endif //__TOOLS_H__
