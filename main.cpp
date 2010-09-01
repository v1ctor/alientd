
#include "tools.h"
#include "enemy.h"
#include "tower.h"


enemy *tmp;
//tower *twr;
tower* twr[10]= {};
int twr_count=0;
//int money = 500;
int count = 0;

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
	
	//~ bullet = SDL_LoadBMP("img/bullet.bmp");
	//~ bullet = SDL_DisplayFormat(bullet);
	

	return;
	}




//----------------------------------------------------------------------
//Рисование башень
void DrawTowers()
{
		for (int i = 0; i<10; i++) 
		{
			
				if (twr[i]!=NULL)
					twr[i]->draw();
			
		 }
	}
//----------------------------------------------------------------------
//Рисование врага
void DrawEnemy()
{ 	
 

	
	}
//----------------------------------------------------------------------	
//Отрисовка всего

void DrawScene(){
	

	DrawTowers();
	DrawEnemy();
	SDL_Flip(screen);
	
	}

//----------------------------------------------------------------------
//Создание башни
void CreateTower(int x,int y)
{
	 if (twr[twr_count]==NULL)
	 {

	 twr[twr_count] = new tower(x-range/2,y-range/2,towerimg,screen);
	 twr[twr_count]->draw();
     twr_count++;
	 money-=100;
	 printf("money=%i\n",money);
	}
	
	}
	
	
	
//----------------------------------------------------------------------
//Продажа башни	
//~ void DeleteTower(int x,int y)
//~ {
		//~ DrawIMG(x,y,ground,screen);
	 	 //~ twr[x][y] = NULL;
	 	 //~ money+=50;
	 	 //~ printf("money=%i\n",money);
	 	//~ // DrawBackground();
	//~ //DrawTowers();
	     //~ 
	//~ 
	//~ }
	
	
	
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

				int x_tmp = event.button.x;
				int y_tmp = event.button.y;
				if (event.button.x <= 600 && 
					event.button.button == 1 && 
					money - 100 >= 0)
							CreateTower(x_tmp,y_tmp);
				//~ if (event.button.x <= 600 && 
					//~ event.button.button == 3)
							//~ DeleteTower(x_tmp,y_tmp);

					
					
			break;

				

		}
		}
		 
		DrawScene();
		
	}
	
	return 0;
}
