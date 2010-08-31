
#include "go.h"

#include <iostream>
#include <stdio.h>


go::go(int x_tmp, int y_tmp, char *dir, SDL_Surface* screen)
{

	x = x_tmp;
	y = y_tmp;
    mScreen = screen;
	SDL_Surface *tmp;
	tmp=SDL_LoadBMP(dir);
	img = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	
	
	
	
	}
	
	
void go::draw()
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(img,NULL,mScreen,&dest);
	return;	
	}
