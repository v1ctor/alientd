
#include "tools.h"
#include "enemy.h"
#include "tower.h"


enemy *enm[10]={};
//tower *twr;
tower* twr[10][10]= {};

//int money = 500;
int count = 0;
int count2 = 0;
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

void Shot(tower *tmp)
{
	if (tmp->attacked != NULL)
	{
	tmp->x_bull_end = tmp->attacked->x_c;
	tmp->y_bull_end = tmp->attacked->y_c;	
	
	DrawIMG(tmp->x_bull,tmp->y_bull,bullet->h,bullet->w,tmp->x_bull,tmp->y_bull,back,screen);
	DrawIMG(tmp->getx(),tmp->gety(),towerimg,screen);
	  
	  
	  
	  int dx = tmp->x_bull_end - tmp->x_bull;
	  int dy = tmp->y_bull_end - tmp->y_bull;
	 double  v = 3/ sqrt(sqr(dx) + sqr(dy));
	int speedx = (int) (v*dx); //(int) (tmp->x_bull_end - tmp->getx()) / 100;
	int speedy = (int) (v*dy);//(int) (tmp->y_bull_end - tmp->gety()) / 100;
	 // printf("%i %i %f\n",speedx,speedy,v*dx);
	tmp->x_bull += speedx;
	tmp->y_bull += speedy;
	  
	DrawIMG(tmp->x_bull,tmp->y_bull,bullet,screen);
}
	
	
	////Может ли кого-нить атаковать?
	//if (tmp->attacked == NULL)
	  //{
		  //DrawIMG(tmp->x_bull,tmp->y_bull,bullet->h,bullet->w,tmp->x_bull,tmp->y_bull,back,screen);
		  //tmp->x_bull_end == -1;
		  //tmp->y_bull_end == -1;
		  //tmp->x_bull = tmp->x_c;
		  //tmp->y_bull = tmp->y_c;
		  //return;
	//}
	
	////Если коненая точка не задана - задать)
	//if(tmp->x_bull_end == -1 && tmp->y_bull_end == -1 )
	//{
		
		//tmp->x_bull_end = tmp->attacked->x_c;
		//tmp->y_bull_end = tmp->attacked->y_c;	
		 //printf("%i %i\n",tmp->attacked->x_c,tmp->attacked->y_c);	
		//}
		
		
	////Рисовать фон	
	//DrawIMG(tmp->x_bull,tmp->y_bull,bullet->h,bullet->w,tmp->x_bull,tmp->y_bull,back,screen);
	////Рисовать башню
	//DrawIMG(tmp->getx(),tmp->gety(),towerimg,screen);  
	      
	      
	 
	//if (sqr(tmp->getx() - tmp->x_bull) + sqr(tmp->gety() - tmp->y_bull) > sqr(tmp->radius))
	  //{
		  
		  //tmp->x_bull_end == tmp->attacked->x_c;
		  //tmp->y_bull_end == tmp->attacked->y_c;
		  //tmp->x_bull = tmp->x_c;
		  //tmp->y_bull = tmp->y_c;
		  //return;
      //}
		  
		
		  ////~ 
	////~ if (tmp->x_bull_end < tmp->getx())
		////~ //tmp->x_bull += speedx;
		////~ 
		////~ 
	////~ if (tmp->x_bull_end > tmp->getx())
		////~ tmp->x_bull += speedx;
		////~ 
	////~ 
	////~ if (tmp->y_bull_end < tmp->gety())
		////~ 
		////~ 
	////~ if (tmp->y_bull_end > tmp->gety())
		////~ 
		
		//tmp->x_bull += speedx;
		//tmp->y_bull += speedy;
		
	//DrawIMG(tmp->x_bull,tmp->y_bull,bullet,screen);
	
	////DrawIMG(enm[i]->getx(),enm[i]->gety(),enm[i]->getimg()->h,enm[i]->getimg()->w,enm[i]->getx(),enm[i]->gety(),back,screen);
	
	
	
	}

//----------------------------------------------------------------------
//Индикация
void Lighting(int x, int y)
{
	
	if (twr[x][y]==NULL && money < 100)	
			DrawIMG(x*range,y*range,deny,screen);
	else
		    DrawIMG(x*range,y*range,allow,screen);
			
			
			
			
	
	
	
	
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
						
						if(twr[i][j]->attacked == NULL)
							for (int k=0;k<10;k++)
								if (twr[i][j]->detect(enm[k])) 
									twr[i][j]->attacked = enm[k];
						Shot(twr[i][j]);
					//~ twr[i][j]->attack();
					//~ 
					//~ if(twr[i][j]->attacked == NULL)	
					//~ for (int k=0;k<10;k++)
						//~ if (twr[i][j]->detect(enm[k])) 
							//~ 
							//~ twr[i][j]->attacked = enm[k];
							//~ 
					//~ Shot(twr[i][j]);//->attacked->getx(),twr[i][j]->attacked->gety(),twr[i][j]);
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
	if (x_twr == 9 && y_twr == 0 || enm[i]->kill)
		{ enm[i] = NULL;
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
		if(enm[i]->getx() < 9*range && enm[i]->gety() > 0)
		{
			enm[i]->move();
			enm[i]->count = 0;
		}
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
    
	enm[0] = new enemy((int)(-2*range+(range - alien->w) / 2),(int)(11*range-(range - alien->h) / 2),alien,screen);
	enm[1] = new enemy((int)(-1*range+(range - alien->w) / 2),(int)(10*range-(range - alien->h) / 2),alien,screen);
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
