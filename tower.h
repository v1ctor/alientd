#ifndef TOWER_H
#define TOWER_H
#include "go.h"
#include "tools.h"


class tower : public go
{
public:
	tower(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface *screen):go(x_tmp,y_tmp,dir,screen){};
	~tower(){};
	void atack();
protected:
	 int radius;
	


};
#endif //__ENEMY_H__
