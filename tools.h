#ifndef TOOLS_H
#define TOOLS_H


#include "SDL.h"
#include "go.h"
#include <iostream>
#include <stdio.h>

static SDL_Surface *screen, *back, *alien, *towerimg, *bullet;
static int money = 500;
static int range = 60;


void DrawIMG(int x, int y, SDL_Surface *img, SDL_Surface* screen);
void DrawIMG(int x, int y, int w, int h, int sx, int sy, SDL_Surface *img, SDL_Surface *screen);
#endif //__TOOLS_H__
