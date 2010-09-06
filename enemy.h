#ifndef ENEMY_H
#define ENEMY_H

#include "go.h"
#include "spisok.h"


class enemy : public go
{
public:
	enemy(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface *screen):go(x_tmp,y_tmp,dir,screen)
	{
			speed = 1;
			count = 0;
			health = 150;
			kill = false;
			price = 50;
			flag = true;
	};
	~enemy(){};
	void move(int x_f,int y_f);
	bool kill;
	//int getxprev(){return x_prev;};
	//int getyprev(){return y_prev;};
	int count;
	int health;
	int price;
	zveno *parth;
	bool flag;
	node middle;
protected:
	int speed;

	//int x_prev;
	//int y_prev;


};
#endif //__ENEMY_H__
