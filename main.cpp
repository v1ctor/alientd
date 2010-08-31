

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "tools.h"
#include "enemy.h"
#include "tower.h"

SDL_Surface *screen, *ground, *road;
//go *tmp;
enemy *tmp;
//tower *twr;
tower* twr[10][10] = {};


void InitImages()
{
	//SDL_Surface *tmp;
	road = SDL_LoadBMP("img/road.bmp");
	road = SDL_DisplayFormat(road);
	
	ground = SDL_LoadBMP("img/ground.bmp");
	ground = SDL_DisplayFormat(ground);
	
	}


	
void DrawBackground()
{
		for (int i = 0; i<10; i++) 
		{
			for (int j = 0; j<10; j++)
			{
				if (field[i][j] == 1)
						{DrawIMG(60*i,60*j,road,screen);}
				if (field[i][j] == 0)
						{DrawIMG(60*i,60*j,ground,screen);}
				if (twr[i][j]!=NULL)
						twr[i][j]->draw();
			}
		 }
	}

void DrawScene(){
	

	 DrawBackground();


	//tmp->draw();
	//if(twr!=NULL)
	//{
		//twr->draw();
		//}
	SDL_Flip(screen);
	
	}

void CreateTower(int x,int y)
{
	 if (twr[x][y]==NULL)
	 {
		 printf("%i,%i\n",x,y);
	 twr[x][y]  = new tower(60*x,60*y,"img/ball.bmp",screen);
	}
	
	}
void DeleteTower(int x,int y)
{
	
	 	 twr[x][y] = NULL;
	
	
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
		
		

	tmp = new enemy(360,0,"img/ball.bmp",screen);
	InitImages();
	
	
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
				int x_tmp = (int)(event.button.x / 60);
				int y_tmp = (int)(event.button.y / 60);
				if(field[x_tmp][y_tmp]!=1 && event.button.x <= 600 && event.button.button == 1)
					CreateTower(x_tmp,y_tmp);
				if(twr[x_tmp][y_tmp]!=NULL && event.button.x <= 600 && event.button.button == 3)
					DeleteTower(x_tmp,y_tmp);
					
                break;

				

		}
		}
		
		DrawScene();
		
	}
	
	return 0;
}
