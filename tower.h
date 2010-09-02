#ifndef TOWER_H
#define TOWER_H
#include "go.h"
#include "enemy.h"



class tower : public go
{
public:
	tower(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface *screen):go(x_tmp,y_tmp,dir,screen)
	{
		x_c = (int) (x + 0.5 * range);
		y_c = (int) (y + 0.5 * range);
		radius = (int) range;// + 0.5 * range;
		attacked = NULL;
		speed = 1;
		x_bull_end = -1;
		y_bull_end = -1;
		
		x_bull = x_c;
		y_bull = y_c;
	};
	~tower(){};
	void attack();//enemy *tmp);//int x, int y);
	bool detect(enemy *tmp);
	enemy *attacked;
	int x_bull,y_bull,x_bull_end,y_bull_end;
	int x_c,y_c;
protected:
	 int radius;
	 int speed;
	 
	 
	 
	 //int x_prev,y_prev;



};
#endif //__ENEMY_H__
