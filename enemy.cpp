
#include "enemy.h"
#include <iostream>
#include <stdio.h>


void enemy::move()
{
			//~ printf("x - %i   %i\n",x,x_prev);
			//~ printf("y - %i   %i\n",y,y_prev);
		
			
			if(x > 0 && field[x-1][y]==1 && x-1 != x_prev)
				{x_prev = x; y_prev = y; x--; return;}
			
			if(x < 9 && field[x+1][y]==1 && x+1 != x_prev)
				{x_prev = x; y_prev = y; x++; return;}
		
			if(y > 0 &&  field[x][y-1]==1 && y-1 != y_prev)
				{y_prev = y; x_prev = x; y--; return;}
			
			if(y < 9 && field[x][y+1]==1 && y+1 != y_prev)
				{y_prev = y; x_prev = x; y++; return;}

		end = 1;
		return;
	
	}
