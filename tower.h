#ifndef TOWER_H
#define TOWER_H
#include "go.h"



class tower : public go
{
public:
	tower(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface *screen):go(x_tmp,y_tmp,dir,screen){};
	~tower(){};
	void attack();//int x, int y);
	void detect();
protected:
	 int radius;
	 int x_prev,y_prev;



};
#endif //__ENEMY_H__
