#include "tools.h"

//----------------------------------------------------------------------
//Загрузка изображений
void InitImages()
{
	//SDL_Surface *tmp;
	road = SDL_LoadBMP("img/road.bmp");
	road = SDL_DisplayFormat(road);	
	
	ground = SDL_LoadBMP("img/ground.bmp");
	ground = SDL_DisplayFormat(ground);
	
	towerimg = SDL_LoadBMP("img/tower.bmp");
	towerimg = SDL_DisplayFormat(towerimg);
	
	alien = SDL_LoadBMP("img/zerg.bmp");
	alien = SDL_DisplayFormat(alien);
	
	
	bullet = SDL_LoadBMP("img/bullet.bmp");
	bullet = SDL_DisplayFormat(bullet);
	
	if(road!=NULL && ground!=NULL && towerimg!=NULL && alien!=NULL && bullet!=NULL)
		printf("%s\n","images init");
	return;
	}
    
void DrawIMG(int x, int y, SDL_Surface *img, SDL_Surface* screen)
{
	SDL_SetColorKey(img,SDL_SRCCOLORKEY,SDL_MapRGB(img->format,0,255,0));
	//tmp=SDL_LoadBMP(dir);
	//tmp = SDL_DisplayFormat(tmp);
	SDL_Rect dest;
	dest.x = x*range;
	dest.y = y*range;
	SDL_BlitSurface(img,NULL,screen,&dest);
	//SDL_FreeSurface(tmp);
	
	
	}
	
void DrawIMG(int x, int y, int w, int h, int sx, int sy, SDL_Surface *img, SDL_Surface *screen)
{
	
	SDL_SetColorKey(img,SDL_SRCCOLORKEY,SDL_MapRGB(img->format,0,255,0));
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	
	SDL_Rect src;
	src.x = sx;
	src.y = sy;
	src.w = w;
	src.h = h;
		
	SDL_BlitSurface(img, &src, screen, &dest);
	}
