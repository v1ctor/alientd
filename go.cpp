
#include "go.h"



go::go(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface* screen)
{
	x = x_tmp;
	y = y_tmp;
    mScreen = screen;
	img = dir;
	x_c = (int) (x + 0.5 * img->h);
	y_c = (int) (y + 0.5 * img->w);
}
	
	
void go::draw()
{	
	DrawIMG(x,y,img,mScreen);
	return;	
}
	
