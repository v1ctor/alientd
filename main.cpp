
#include "tools.h"
#include "enemy.h"
#include "tower.h"
//~ #include "spisok.h"
#include "pathfinder.h"


enemy *enm[10]={};
//tower *twr;
tower* twr[r_count][r_count]= {};

//int money = 500;
int count = 0;
int count2 = 0;
int enm_count;
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
	
	bullet = SDL_LoadBMP("img/bullet.bmp");
	bullet = SDL_DisplayFormat(bullet);
	

	return;
	}
	
	
void CreateEnemy()
{
	if (enm_count < 10 && enm_count != 0 && (int)(enm[enm_count-1]->getx()/range) > 0)// || (int)(enm[enm_count-1]->gety()/range)) < 9)
	{
	enm[enm_count] = new enemy((int)(0*range+(range - alien->w) / 2),(int)(9*range+(range - alien->h) / 2),alien,screen);
	enm_count++;
}
	
	}	
	
bool CheckParth()
{
	zveno *tmp;
	for (int i=0; i<9; i++)
		if (enm[i] != NULL)
		{	
			tmp = get_parth((int)(enm[i]->getx()/range),(int)(enm[i]->gety()/range),9,0);
				//printf("%s\n","check parth");
			if (tmp == NULL)	
				{	del(tmp);
					//printf("%s\n","not tower");
						//~ char s[80];
		             //~ gets(&s[0]);
					return false;}
	     }
	delete tmp;	
 //printf("%s\n","yes tower");
	return true;
}
	
	
	
	

void Shot(tower *tmp)
{
	
	//~ Если обнаружен враг
	if (tmp->attacked != NULL)
	{
		//Считывание координат врага
	tmp->x_bull_end = tmp->attacked->x_c;
	tmp->y_bull_end = tmp->attacked->y_c;	
	
	//Отрисовка фона и башни
	DrawIMG(tmp->x_bull,tmp->y_bull,bullet->h,bullet->w,tmp->x_bull,tmp->y_bull,back,screen);
	DrawIMG(tmp->getx(),tmp->gety(),towerimg,screen);
	  
	  
	  //Расстояние по х и у от пули до врага
	  int dx = tmp->x_bull_end - tmp->x_bull;
	  int dy = tmp->y_bull_end - tmp->y_bull;

	  //if(abs(dx) < (int) tmp->attacked->getimg()->h / 2 && abs(dy) < (int) tmp->attacked->getimg()->h / 2 )
	  if(abs(dx) < tmp->speed && abs(dy) < tmp->speed )
	  {
		 // printf("%i %i,",tmp->x_bull,tmp->y_bull);
		 tmp->attacked->health -= tmp->power;
		 money+=5;
		 tmp->x_bull=tmp->x_c;
		 tmp->y_bull=tmp->y_c;		 
		 return;
		}
		else
		 { 
		  //Коэффициэнт подобия
	 double  v = tmp->speed/ sqrt(sqr(dx) + sqr(dy));
	
	//Скорости х и у
	int speedx = (int) (v*dx);
	int speedy = (int) (v*dy);

	//перемещение
	tmp->x_bull += speedx;
	tmp->y_bull += speedy;
	  
	//Отрисовка пули
	DrawIMG(tmp->x_bull,tmp->y_bull,bullet,screen);
	
}
}

return;
	
	}

//----------------------------------------------------------------------
//Индикация
void Lighting(int x, int y)
{
	//add_tower(x,y);		
	if (twr[x][y]==NULL && money < 100)// || !CheckParth())	
	
			DrawIMG(x*range,y*range,deny,screen);
	
	else
		    DrawIMG(x*range,y*range,allow,screen);
	//del_tower(x,y);
	}


//----------------------------------------------------------------------
//Рисование башень
void DrawTowers()
{
	if (count2 == 20)
	{
		for (int i = 0; i<10; i++) 
		{
			for (int j = 0; j<10; j++) 
		{
			
			//~ Если башня существует
				if (twr[i][j]!=NULL)
					{
						
						
						
						
						twr[i][j]->attack();
						
						
	                    if (twr[i][j]->attacked != NULL)
	 
						//printf("%i\n",attacked->health);
						if (twr[i][j]->attacked->kill || !twr[i][j]->detect(twr[i][j]->attacked))
						{
							DrawIMG(twr[i][j]->x_bull,twr[i][j]->y_bull,bullet->h,
							bullet->w,twr[i][j]->x_bull,twr[i][j]->y_bull,back,screen);
							DrawIMG(twr[i][j]->getx(),twr[i][j]->gety(),towerimg,screen);
							twr[i][j]->attacked = NULL;
						}
						
						if(twr[i][j]->attacked == NULL)
							for (int k=0;k<10;k++)
								if (twr[i][j]->detect(enm[k])) 
									twr[i][j]->attacked = enm[k];
						Shot(twr[i][j]);

					}
		 }
	 }
		 count2 = 0;
	}
	count2++;
}






//----------------------------------------------------------------------
//Рисование врага
void DrawEnemy()
{ 	
	
for (int i=0; i<9; i++)
{ if (enm[i]!=NULL)
	{
		
	int x_twr = (int) enm[i]->getx() / range;
	int y_twr = (int) enm[i]->gety() / range;
	
	
	DrawIMG(enm[i]->getx(),enm[i]->gety(),enm[i]->getimg()->h,enm[i]->getimg()->w,enm[i]->getx(),enm[i]->gety(),back,screen);
	if (x_twr == 9 && 
	    y_twr == 0 || 
	    enm[i]->kill)
		{ 	
			enm[i]->kill = true;
			enm[i] = NULL;
			enm_count --;
			continue;
		}
	
	
	if (twr[x_twr][y_twr]!=NULL)
		twr[x_twr][y_twr]->draw();
	if (x_twr < 9 && twr[x_twr + 1][y_twr]!=NULL)
		twr[x_twr + 1][y_twr]->draw();
	if (y_twr < 9 && twr[x_twr][y_twr + 1]!=NULL)
		twr[x_twr][y_twr + 1]->draw();
	if (x_twr < 9 && y_twr < 9 && twr[x_twr + 1][y_twr + 1]!=NULL)
		twr[x_twr + 1][y_twr + 1]->draw();
	
	
	if (enm[i]->count == 16)
	{ 
		
		enm[i]->move(540,0);
		CreateEnemy();

		enm[i]->count = 0;
	}
	
	enm[i]->draw();
	enm[i]->count++;
	
}	
}
return;
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
 {		 add_tower(x,y);
	     if (!CheckParth())
			{del_tower(x,y);
			 return;}
         DrawIMG(x*range,y*range,range,range,x*range,y*range,back,screen);
		 twr[x][y] = new tower(x*range,y*range,towerimg,screen);
	     twr[x][y]->draw();
	     
	     for (int i=0; i<9; i++)
			 if (enm[i]!=NULL)
					enm[i]->flag = true;
	     money-=100;
		 printf("money=%i\n",money);
	}
	
//----------------------------------------------------------------------
//Продажа башни	
void DeleteTower(int x,int y)
{
		DrawIMG(x*range,y*range,range,range,x*range,y*range,back,screen);
	 	 twr[x][y] = NULL;
	 	 del_tower(x,y);
	 	   for (int i=0; i<9; i++)
			 if (enm[i]!=NULL)
					enm[i]->flag = true;
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
    
	enm[0] = new enemy((int)(0*range+(range - alien->w) / 2),(int)(9*range+(range - alien->h) / 2),alien,screen);
	//enm[1] = new enemy((int)(0*range+(range - alien->w) / 2),(int)(9*range+(range - alien->h) / 2),alien,screen);
	enm_count = 1;
	
	//enm[2] = new enemy(-3*range,12*range,alien,screen);
	//enm[3] = new enemy(-4*range,13*range,alien,screen);
	

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
