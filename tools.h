#ifndef TOOLS_H
#define TOOLS_H


#include "SDL.h"
#include "go.h"
#include <iostream>
#include <stdio.h>

const int range = 60;
static SDL_Surface *screen, *ground, *road, *alien, *towerimg, *bullet;
static int money = 500;
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

static void InitImages();
void DrawIMG(int x, int y, SDL_Surface *img, SDL_Surface* screen);
void DrawIMG(int x, int y, int w, int h, int sx, int sy, SDL_Surface *img, SDL_Surface *screen)
#endif //__TOOLS_H__
