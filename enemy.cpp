
#include "enemy.h"
#include <iostream>
#include <stdio.h>


void enemy::move()
{
	
	
	if (health>0)
	{
		x+=speed;
		y-=speed;
	
	
    }
    else
    {
		kill = true;
	}
		
		return;
	
	}
