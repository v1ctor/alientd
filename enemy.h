#ifndef ENEMY_H
#define ENEMY_H

#include "go.h"
#include "tools.h"


class enemy : public go
{
public:
	enemy(int x_tmp, int y_tmp, char *dir, SDL_Surface *screen):go(x_tmp,y_tmp,dir,screen){};
	~enemy(){};
	void move();
private:
	int speed;
	


};
#endif //__ENEMY_H__
