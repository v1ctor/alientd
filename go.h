#ifndef GO_H
#define GO_H

#include "SDL.h"
#include "tools.h"

class go
{
public:
	go(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface *screen);//, int price_tmp, int health_tmp);
	~go() {};
	void setx(int tmp){x = tmp;};
	void sety(int tmp){y = tmp;};
	SDL_Surface* getimg(){return img;};
	int getx(){return x;};
	int gety(){return y;};
	void draw();
protected:
	int x,y;
	SDL_Surface *img;
	SDL_Surface *mScreen;
	//int price;
	//int health;
};
#endif //__GO_H__
