

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "tools.h"
#include "enemy.h"
#include "tower.h"

SDL_Surface *screen;
//go *tmp;
enemy *tmp;
tower *twr;




	
void DrawBackground()
{
		for (int i = 0; i<10; i++)
	for (int j = 0; j<10; j++)
		if (field[i][j] == 1)
			{DrawIMG(60*j,60*i,"img/road.bmp",screen);}
		else
			{DrawIMG(60*j,60*i,"img/ground.bmp",screen);}
			
		
	}

void DrawScene(){
	

	DrawBackground();

	SDL_Rect dest;
	tmp->draw();
	if(twr!=NULL)
	{
		twr->draw();
		}
	SDL_Flip(screen);
	
	}

void CreateTower(int x,int y)
{
	 twr = new tower(60*x,60*y,"img/ball.bmp",screen);
	 
	
	}




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
		
		
  //  tmp = new go(99,77, "img/ball.bmp",screen);
	tmp = new enemy(360,0,"img/ball.bmp",screen);
	
	
	
	//SDL_ShowCursor(0);
	//InitImages();
	int done=0;
	while (done == 0)
	{	
		SDL_Event event;	
		
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT: 
				done = 1;
				break;
			case SDL_KEYDOWN:			
				if (event.key.keysym.sym == SDLK_ESCAPE) {done = 1;}
				break;
			case SDL_MOUSEBUTTONDOWN:
				printf("Mouse button %d pressed at (%d,%d)\n",
				event.button.button, (int)(event.button.x / 60), (int)(event.button.y/60));
				CreateTower((int)(event.button.x / 60),(int)(event.button.y/60));
                break;

				

		}
		}
		
		DrawScene();
		
	}
	
	return 0;
}
