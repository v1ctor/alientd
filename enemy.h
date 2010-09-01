#ifndef ENEMY_H
#define ENEMY_H

#include "go.h"


class enemy : public go
{
public:
	enemy(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface *screen):go(x_tmp,y_tmp,dir,screen)
	{x_prev = -1;
	y_prev = -1;
	end = 0;};
	~enemy(){};
	void move();
	int end;
	int getxprev(){return x_prev;};
	int getyprev(){return y_prev;};
protected:
	int speed;
	int x_prev;
	int y_prev;


};
#endif //__ENEMY_H__
