

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "go.h"

SDL_Surface *screen;
go *tmp;

void DrawScene(){
	
	SDL_Rect dest;
	//dest.x = 100;
	//dest.y = 100;
	//SDL_BlitSurface(SDL_LoadBMP("img/ball.bmp"),NULL,screen,&dest);
	tmp->draw();
	SDL_Flip(screen);
	
	};






int main(int argc, char** argv)
{
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
		
		
    tmp = new go(99,77, "img/ball.bmp",screen);
	
	
	
	
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
