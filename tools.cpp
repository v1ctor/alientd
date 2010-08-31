#include "tools.h"


	            
void DrawIMG(int x, int y, char* dir, SDL_Surface* screen)
{
	SDL_Surface *tmp;
	tmp=SDL_LoadBMP(dir);
	tmp = SDL_DisplayFormat(tmp);
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(tmp,NULL,screen,&dest);
	SDL_FreeSurface(tmp);
	
	}
