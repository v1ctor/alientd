#include "tools.h"




    
void DrawIMG(int x, int y, SDL_Surface *img, SDL_Surface* screen)
{
	SDL_SetColorKey(img,SDL_SRCCOLORKEY,SDL_MapRGB(img->format,0,255,0));
	//tmp=SDL_LoadBMP(dir);
	//tmp = SDL_DisplayFormat(tmp);
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(img,NULL,screen,&dest);
	//SDL_FreeSurface(tmp);
	
	
	}
