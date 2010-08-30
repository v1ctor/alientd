
#include "go.h"

#include <iostream>
#include <stdio.h>

go::go(int x_tmp, int y_tmp, char *dir,SDL_Surface *screen)
{
	
	go::x = x_tmp;
	printf("%s",dir);
	go::y = y_tmp;
	SDL_Surface *tmp;
	go::img = SDL_LoadBMP(dir);
	//img = SDL_DisplayFormat(tmp);
	//go::img = tmp;
	SDL_FreeSurface(tmp);
	go::mScreen = screen;
	
	
	
	
	}
	
	
void go::draw()
{
	SDL_Rect dest;
	dest.x = 200;//tmp->getx();
	//printf("%X",tmp->getx());
	dest.y = 200;//tmp->gety();
	SDL_BlitSurface(go::img,NULL,go::mScreen,&dest);
	//SDL_Flip(screen);
	//return;
	
	}
