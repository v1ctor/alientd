
#include "enemy.h"
#include <iostream>
#include <stdio.h>
#include "pathfinder.h"



void enemy::move(int x_f,int y_f)
{
	
	x_c = (int) (x + 0.5 * range);
	y_c = (int) (y + 0.5 * range);
	
	if (health>0)
	{
			   
	    if (flag)
	    {	printf("%s\n","666");
			parth = get_parth((int)(x/range),(int)(y/range),(int)(x_f/range),(int)(y_f/range));
			print(parth);
			flag = false;
			parth = pop(parth);
			middle = parth->inf;
		    parth = pop(parth);
		}
		
		printf("%i %i %i %i\n",x,y,middle.x*range,middle.y*range);
		//~ char s[80];
		//~ gets(&s[0]);
		
		if ( abs(x - middle.x*range) >= speed || abs(y - middle.y*range) >= speed)
		{
			if (x < middle.x*range)
				x+=speed;
			if (x > middle.x*range)
				x-=speed;
			if (y < middle.y*range)
				y+=speed;
			if (y > middle.y*range)
				y-=speed;
			//printf("%s\n","3");
			
		}
			else
		{
			printf("%s\n","4");
		    middle = parth->inf;
		    parth = pop(parth);
		    
	    }
	
    }
    else
    {
		kill = true;
		//~ money += price;
		//~ printf("денег = %i\n",money);
	}
		
		return;
	
	}
