#ifndef TOWER_H
#define TOWER_H
#include "go.h"
#include "tools.h"


class tower : public go
{
public:
	tower(int x_tmp, int y_tmp, char *dir, SDL_Surface *screen):go(x_tmp,y_tmp,dir,screen){};
	~tower(){};
	void atack();
private:
	 int radius;
	


};
#endif //__ENEMY_H__
