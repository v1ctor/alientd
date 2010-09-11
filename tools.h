#ifndef TOOLS_H
#define TOOLS_H
#define sqr(x) ((x)*(x))


#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "go.h"
//#include "enemy.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

static SDL_Surface *screen, *back, *alien, *towerimg, *bullet, *allow, *deny, *startimg, *menu;
static int money = 500;
static const int range = 60;
static const int r_count = 10;


void DrawIMG(int x, int y, SDL_Surface *img, SDL_Surface* screen);
void DrawIMG(int x, int y, int w, int h, int sx, int sy, SDL_Surface *img, SDL_Surface *screen);
#endif //__TOOLS_H__
