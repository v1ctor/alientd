
#include "enemy.h"
#include <iostream>
#include <stdio.h>


void enemy::move()
{
			printf("%i\n",x);
			printf("%i\n",y);
			xt=x;
			yt=y;
			if(x > 0 && field[x-1][y]==1 && x-1 != x_prev)
				{x_prev = x; y_prev = -1; x--; return;}
			
			if(x < 9 && field[x+1][y]==1 && x+1 != x_prev)
				{x_prev = x; y_prev = -1; x++; return;}
		
			if(y > 0 &&  field[x][y-1]==1 && y-1 != y_prev)
				{y_prev = y; x_prev = -1; y--; return;}
			
			if(y < 9 && field[x][y+1]==1 && y+1 != y_prev)
				{y_prev = y; x_prev = -1; y++; return;}
			
		
	if(xt == x && yt == y)
		end = 1;
	
	}
