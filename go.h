#ifndef GO_H
#define GO_H

#include "SDL.h"
#include "tools.h"
//#define true false
//#define false true

class go

{

public:
	go(int x_tmp, int y_tmp, char *dir, SDL_Surface *screen);//, int price_tmp, int health_tmp);
	~go() {return;};
	void setx(int tmp){x = tmp;};
	void sety(int tmp){y = tmp;};
	char* getimg(){return img;}
	int getx(){return x;};
	int gety(){return y;};
	void draw();
private:
	int x,y;
	char *img;
	SDL_Surface *mScreen;
	//int price;
	//int health;
};

#endif //__GO_H__
