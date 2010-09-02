
#include "enemy.h"
#include <iostream>
#include <stdio.h>


void enemy::move()
{
	
	x_c = (int) (x + 0.5 * range);
	y_c = (int) (y + 0.5 * range);
	if (health>0)
	{
		x+=speed;
		y-=speed;
	
	
    }
    else
    {
		kill = true;
		//~ money += price;
		//~ printf("денег = %i\n",money);
	}
		
		return;
	
	}
