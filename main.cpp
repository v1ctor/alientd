
#include "tools.h"
#include "enemy.h"
#include "tower.h"


enemy *tmp;
//tower *twr;
tower* twr[10][10]= {};

//int money = 500;
int count = 0;
int x_vsp = -1,y_vsp = -1;

//----------------------------------------------------------------------
//Загрузка изображений
void InitImages()
{
	//SDL_Surface *tmp;
	back = SDL_LoadBMP("img/back.bmp");
	back = SDL_DisplayFormat(back);	

	
	towerimg = SDL_LoadBMP("img/tower.bmp");
	towerimg = SDL_DisplayFormat(towerimg);
	
	alien = SDL_LoadBMP("img/zerg.bmp");
	alien = SDL_DisplayFormat(alien);
	
	allow = SDL_LoadBMP("img/allow.bmp");
	allow = SDL_DisplayFormat(allow);
	
	deny = SDL_LoadBMP("img/deny.bmp");
	deny = SDL_DisplayFormat(deny);
	
	//~ bullet = SDL_LoadBMP("img/bullet.bmp");
	//~ bullet = SDL_DisplayFormat(bullet);
	

	return;
	}



//----------------------------------------------------------------------
//Индикация
void Lighting(int x, int y)
{
	
	if (twr[x][y]==NULL && money >= 100)	
		{
	         x = x*range;
	         y = y*range;
			DrawIMG(x,y,allow,screen);
		}
		else
		{
			x = x*range;
	         y = y*range;
			DrawIMG(x,y,deny,screen);
			
			
			}
	
	
	
	
	}


//----------------------------------------------------------------------
//Рисование башень
void DrawTowers()
{
		for (int i = 0; i<10; i++) 
		{
			for (int j = 0; j<10; j++) 
		{
				if (twr[i][j]!=NULL)
					twr[i][j]->draw();
			}
		 }
	}
//----------------------------------------------------------------------
//Рисование врага
void DrawEnemy()
{ 	
	DrawIMG(tmp->getx(),tmp->gety(),range,range,tmp->getx(),tmp->gety(),back,screen);
	if (count == 15)
	{ 
	if(tmp->getx() < 9*range && tmp->gety() > 0)
	{
		tmp->move();
		
		count = 0;
     }
 }
	tmp->draw();
     count++;

	
	}
//----------------------------------------------------------------------	
//Отрисовка всего

void DrawScene(){
	

	//DrawTowers();
	
	DrawEnemy();
	SDL_Flip(screen);
	
	
	}

//----------------------------------------------------------------------
//Создание башни
void CreateTower(int x,int y)
{        DrawIMG(x*range,y*range,range,range,x*range,y*range,back,screen);
		 twr[x][y] = new tower(x*range,y*range,towerimg,screen);
	     twr[x][y]->draw();
	     money-=100;
		 printf("money=%i\n",money);
	}
	
	
	
	
	
//----------------------------------------------------------------------
//Продажа башни	
void DeleteTower(int x,int y)
{
		DrawIMG(x*range,y*range,range,range,x*range,y*range,back,screen);
	 	 twr[x][y] = NULL;
	 	 money+=50;
	 	 printf("money=%i\n",money);
	 	// DrawBackground();
	//DrawTowers();
	     
	
	}
	
	
	
//----------------------------------------------------------------------
//MAIN LOOP
int main(int argc, char** argv)
{
//----------------------------------------------------------------------	
//Инициализация SDL 
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
//----------------------------------------------------------------------		
	
//Иниацилизация игровых объектов	
	InitImages();
    DrawIMG(0,0,back,screen);
	tmp = new enemy(0,9*range,alien,screen);

//----------------------------------------------------------------------



//MainLoop	
{
	
	int done=0;
	while (done == 0)
	{	
		SDL_Event event;	
		
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				//~ закрытие
				case SDL_QUIT: 
					done = 1;
				break;
			
				//~ нажатие клавиш
				case SDL_KEYDOWN:			
					if (event.key.keysym.sym == SDLK_ESCAPE) {done = 1;}
				break;
			
				//~ клик мышкой 
				case SDL_MOUSEBUTTONDOWN:

					int x_tmp, y_tmp;
					x_tmp = (int) event.button.x / range;
					y_tmp = (int) event.button.y / range;
					if (twr[x_tmp][y_tmp] == NULL &&
						event.button.x <= 600 && 
						event.button.button == 1 && 
						money - 100 >= 0)
							CreateTower(x_tmp,y_tmp);
					if (twr[x_tmp][y_tmp] != NULL &&
						event.button.x <= 600 && 
						event.button.button == 3)
							DeleteTower(x_tmp,y_tmp);
				break;
			
				//~ движение мыши
				case SDL_MOUSEMOTION:			
					int x,y;
					SDL_GetMouseState(&x,&y);
					x = (int)x/range;
					y = (int)y/range;
				
					if (x_vsp != x || y_vsp != y)
					{ 
						DrawIMG(x_vsp*range,y_vsp*range,range,range,x_vsp*range,y_vsp*range,back,screen);
						if (twr[x_vsp][y_vsp]!=NULL)
							twr[x_vsp][y_vsp]->draw();
					}
					
					if (x<10)
					{
						Lighting(x,y);
						x_vsp = x;
						y_vsp = y;
					}
				
				break;

				

			}
		}
		 
		DrawScene();
		
	}
}

	return 0;
}
