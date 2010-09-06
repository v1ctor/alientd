
#include "enemy.h"
#include <iostream>
#include <stdio.h>
#include "pathfinder.h"
bool flag = true;
static zveno *middle;
void enemy::move(int x_f,int y_f)
{
	
	x_c = (int) (x + 0.5 * range);
	y_c = (int) (y + 0.5 * range);
	
	if (health>0)
	{
		zveno *path;
	   
	    if (flag)
	    {	
			path = get_path((int)(x/range),(int)(y/range),(int)(x_f/range),(int)(y_f/range));
			print(path);
			flag = false;
		}
		middle = pop(path);
	
		if (x != middle->inf.x && y != middle->inf.y)
		{
			x+=speed;
	    	y-=speed;
			
		}
			else
		{
		    middle = pop(path);
		    
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
