
#include "go.h"



go::go(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface* screen)
{
	x = x_tmp;
	y = y_tmp;
    mScreen = screen;
	img = dir;
}
	
	
void go::draw()
{	
	DrawIMG(x,y,img,mScreen);
	return;	
}
	
