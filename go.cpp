
#include "go.h"

#include <iostream>
#include <stdio.h>


go::go(int x_tmp, int y_tmp, char *dir, SDL_Surface *screen)
{
	
	printf("%s","Я констукторко!\n");
	printf("x_tmp=%i\n",x_tmp);
	
	
	x = x_tmp;
	y = y_tmp;
	SDL_Surface *tmp;
	img = SDL_LoadBMP(dir);
	//img = SDL_DisplayFormat(tmp);
	//go::img = tmp;
	SDL_FreeSurface(tmp);
	mScreen = screen;
	
	
	
	}
	
	
void go::draw()
{
	
	//printf("%s","Йа рисовалко!\n");
	SDL_Rect dest;
	dest.x = 200;//tmp->getx();
	//printf("%i",dest.x);
	dest.y = 200;//tmp->gety();
	SDL_BlitSurface(img,NULL,mScreen,&dest);
	//SDL_Flip(screen);
	//return;
	
	}
