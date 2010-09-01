
#include "tools.h"
#include "enemy.h"
#include "tower.h"

//SDL_Surface *screen, *ground, *road, *alien, *towerimg;
//go *tmp;
enemy *tmp;
//tower *twr;
tower* twr[10][10] = {};
//int money = 500;
int count = 0;

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
	
	//~ bullet = SDL_LoadBMP("img/bullet.bmp");
	//~ bullet = SDL_DisplayFormat(bullet);
	
	if(road!=NULL && ground!=NULL && towerimg!=NULL && alien!=NULL && bullet!=NULL)
		printf("%s\n","images init");
	return;
	}




//----------------------------------------------------------------------
//Отрисовка заднего фона	
void DrawBackground()
{
		for (int i = 0; i<10; i++) 
		{
			for (int j = 0; j<10; j++)
			{
				if (field[i][j] == 1)
						{DrawIMG(i,j,road,screen);}
				if (field[i][j] == 0)
						{DrawIMG(i,j,ground,screen);}
				if (twr[i][j]!=NULL)
						twr[i][j]->draw();
			}
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
						//twr[i][j]->attack();//i*range+100,j*range+100);
			}
		 }
		 SDL_Flip(screen);
	}
//----------------------------------------------------------------------
//Рисование врага
void DrawEnemy()
{ 	
     if (!tmp->end)
     {	 
		if(count == 100)
		{	DrawIMG(tmp->getxprev(),tmp->getyprev(),road,screen);
			tmp->draw();
			tmp->move();
		 count=0;
		 }
	}
	SDL_Flip(screen);
	//~ else
	//~ {
		//~ DrawIMG(tmp->getx(),tmp->gety(),road,screen);
	//~ }
	
	}
//----------------------------------------------------------------------	
//Отрисовка всего

void DrawScene(){
	
	//DrawBackground();
	DrawTowers();
	DrawEnemy();
	//SDL_Flip(screen);
	count++;
	
	}

//----------------------------------------------------------------------
//Создание башни
void CreateTower(int x,int y)
{
	 if (twr[x][y]==NULL)
	 {
		 //printf("%i,%i\n",x,y);
	 twr[x][y]  = new tower(x,y,towerimg,screen);
	 twr[x][y]->draw();
	// DrawBackground();
	// DrawTowers();
	 money-=100;
	 printf("money=%i\n",money);
	}
	
	}
	
//----------------------------------------------------------------------
//Продажа башни	
void DeleteTower(int x,int y)
{
		DrawIMG(x,y,ground,screen);
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
	if(road==NULL)
	 printf("%s\n","error");
	DrawBackground();
	tmp = new enemy(9,2,alien,screen);

//----------------------------------------------------------------------
	
	
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

				int x_tmp = (int)(event.button.x / 60);
				int y_tmp = (int)(event.button.y / 60);
				if (field[x_tmp][y_tmp]!=1 && 
					event.button.x <= 600 && 
					event.button.button == 1 && 
					money - 100 >= 0)
							CreateTower(x_tmp,y_tmp);
				if (twr[x_tmp][y_tmp]!=NULL && 
					event.button.x <= 600 && 
					event.button.button == 3)
							DeleteTower(x_tmp,y_tmp);

					
					
			break;

				

		}
		}
		 
		DrawScene();
		
	}
	
	return 0;
}
