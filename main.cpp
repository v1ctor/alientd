

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "go.h"

SDL_Surface *screen;
go *tmp;

void DrawScene(){
	
	SDL_Rect dest;
	dest.x = 100;//tmp->getx();
	//printf("%X",tmp->getx());
	dest.y = 100;//tmp->gety();
	SDL_BlitSurface(SDL_LoadBMP("/home/v1ctor/git/ATA/img/ball.bmp"),NULL,screen,&dest);
	tmp->draw();
	SDL_Flip(screen);
	
	};






int main(int argc, char** argv)
{

	tmp = new go((int)99,(int)77, "/home/v1ctor/git/ATA/img/ball.bmp",screen);
	//go tmp
	//tmp->setx(20);
	
	
	
	//printf(go);
	//printf("x=%X",tmp.getx());





	
	if (SDL_Init(SDL_INIT_VIDEO)<0)
		{
			printf("Error");
			exit(1);	
		}
	
	atexit(SDL_Quit);
	
	SDL_WM_SetCaption("ATA","ata");
	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if (screen == NULL)
		{
			printf("Error");
			exit(1);				
		}
		
	//SDL_ShowCursor(0);
	//InitImages();
	int done=0;
	while (done == 0)
	{	
		SDL_Event event;	
		
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) {done = 1;}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE) {done = 1;}
			}
		}
		
		DrawScene();
		
	}
	
	return 0;
}
