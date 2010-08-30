

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "go.h"

SDL_Surface *screen;


void DrawScene(){
	
	
	SDL_Flip(screen);
	
	
	};






int main(int argc, char** argv)
{
	go tmp;
	tmp.setx(2);
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
