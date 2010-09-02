
#include <iostream>
#include "tower.h"
#include "tools.h"



void tower::attack()//enemy *tmp)
{	
			//~ DrawIMG(x_bull,y_bull,bullet->h,bullet->w,x_bull,y_bull,back,screen);
	        //~ DrawIMG(getx(),gety(),towerimg,screen);
	
 
}


bool tower::detect(enemy *tmp)
{
	if (tmp == NULL) return false;
	
	int x_tmp = tmp->getx();
	int y_tmp = tmp->gety();
	int h_tmp = tmp->getimg()->h;
	
	//if (x_tmp + h_tmp > x_c - radius && y_tmp + h_tmp < y_c - radius)
	if (sqrt(sqr(x_tmp + h_tmp - x_c) + sqr(y_tmp + h_tmp - y_c)) < radius ||
		sqrt(sqr(x_tmp + h_tmp - x_c) + sqr(y_tmp - y_c)) < radius || 
		sqrt(sqr(x_tmp - x_c) + sqr(y_tmp + h_tmp - y_c)) < radius ||
		sqrt(sqr(x_tmp - x_c) + sqr(y_tmp - y_c)) < radius)	
				//printf ("%i %i %i\n",x_tmp,x_c,radius);
			return true;
		
	
	
	return false;
	}
