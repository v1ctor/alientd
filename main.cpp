
#include "tools.h"
#include "enemy.h"
#include "tower.h"
#include "spisok.h"
#include "pathfinder.h"


enemy *enm[10]={};
zveno *ufo;
//tower *twr;
tower* twr[r_count][r_count]= {};

//int money = 500;
int count = 0;
int count2 = 0;
int enm_count;
int x_vsp = -1,y_vsp = -1;
bool start = false;
SDL_Color clr;// = {255,255,255,0};
SDL_Rect dest;// = {620, 0,0,0};
char* fontname = "font/seed_cyr_medim.ttf";

void print_ttf(SDL_Surface *sDest, char* message, char* font, int size, SDL_Color color, SDL_Rect dest){

 TTF_Font *fnt = TTF_OpenFont(font, size);
 if(!fnt)
    printf("TTF_OpenFont: %s\n", TTF_GetError());
 SDL_Surface *sText = TTF_RenderText_Blended( fnt, message, color);
 SDL_BlitSurface( sText,NULL, sDest,&dest );
 SDL_FreeSurface( sText );
 TTF_CloseFont( fnt );

}



//----------------------------------------------------------------------
//Загрузка изображений
void InitImages()
{
	//SDL_Surface *tmp;
	back = IMG_Load("img/background.png");
	back = SDL_DisplayFormat(back);	
	
	menu = IMG_Load("img/menu.png");
	menu = SDL_DisplayFormat(menu);	

	
	towerimg = IMG_Load("img/tower.png");
	towerimg = SDL_DisplayFormat(towerimg);
	
	alien = IMG_Load("img/ufo.png");
	alien = SDL_DisplayFormat(alien);
	
	allow = IMG_Load("img/allow.png");
	allow = SDL_DisplayFormat(allow);
	
	deny = IMG_Load("img/deny.png");
	deny = SDL_DisplayFormat(deny);
	
	bullet = IMG_Load("img/bullet.png");
	bullet = SDL_DisplayFormat(bullet);
	
	return;
	}
	
	
void CreateEnemy()
{
	if (enm_count < 10 && enm_count != 0 && 
	(	(int)(enm[enm_count-1]->getx()/range) > 0 || 
		(int)(enm[enm_count-1]->gety()/range) < 8)
	)
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
			if (tmp == NULL)	
				{	del(tmp);
					return false;}
	     }
	     tmp = get_parth(0,9,9,0);
			if (tmp == NULL)	
				{	del(tmp);
					return false;}
	delete tmp;	
	return true;
}
	
void CheckMoney()
{	
		clr = {0,255,240,0};
		dest = {620, 60,0,0};
		
		DrawIMG(dest.x - 20 ,dest.y,200,22,0,0,menu,screen);
		
		print_ttf(screen, "Money:" , fontname, 20, clr, dest);
		dest = {700, 60,0,0};

		
		char* buff = new char();
		sprintf(buff, "%i", money);
		print_ttf(screen, buff, fontname, 20, clr, dest);
		delete buff;
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
		 
		 CheckMoney();
		 
		 
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
	if (/*!CheckParth() || */(twr[x][y]==NULL && money < 100))	
			{
			//del_tower(x,y);
			DrawIMG(x*range,y*range,deny,screen);
		}
	
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
	if (start)
	{
		DrawEnemy();
	}
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
CheckMoney();
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
	 	
CheckMoney();
	}
	

	
	
void end()
{
		

TTF_Quit();
SDL_Quit();
IMG_Quit();
	
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
	 	

	if(TTF_Init()==-1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted=IMG_Init(flags);
	if(initted&flags != flags) 
		{
		printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
		}

	
	SDL_WM_SetCaption("AlienTD","AlienTD");
	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if (screen == NULL)
		{
			printf("Error");
			exit(1);				
		}
	//SDL_WM_ToggleFullScreen (screen);
//----------------------------------------------------------------------		
	
//Иниацилизация игровых объектов	
	InitImages();
    DrawIMG(0,0,back,screen);
    DrawIMG(600,0,menu,screen);
	clr = {255,255,255,0};
	dest = {620, 0,0,0};
	print_ttf(screen, "START" , fontname, 60, clr, dest);
	CheckMoney();


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
				//	printf ("%i %i\n",x_tmp,y_tmp);
					if (twr[x_tmp][y_tmp] == NULL &&
						event.button.x <= 600 && 
						event.button.button == 1 && 
						money - 100 >= 0)
							CreateTower(x_tmp,y_tmp);
					if (twr[x_tmp][y_tmp] != NULL &&
						event.button.x <= 600 && 
						event.button.button == 3)
							DeleteTower(x_tmp,y_tmp);
					if (!start && x_tmp > 9 && x_tmp < 14 && y_tmp == 0)
						{	
						start = true;
						enm[0] = new enemy((int)(0*range+(range - alien->w) / 2),(int)(9*range+(range - alien->h) / 2),alien,screen);
						enm_count = 1;
						}
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
