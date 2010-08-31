
#include "go.h"


#include <iostream>
#include <stdio.h>


go::go(int x_tmp, int y_tmp, char *dir, SDL_Surface* screen)
{

	x = x_tmp;
	y = y_tmp;
    mScreen = screen;
	img=SDL_LoadBMP(dir);
	img = SDL_DisplayFormat(img);
	//SDL_FreeSurface(tmp);
	
	
	
	
	}
	
	
void go::draw()
{
	
	
	DrawIMG(x,y,img,mScreen);
	//SDL_Rect dest;
	//dest.x = x;
	//dest.y = y;
	//SDL_BlitSurface(img,NULL,mScreen,&dest);
	return;	
	}
	
