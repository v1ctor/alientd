#include "pathfinder.h"
#include <stdio.h>

//~ 
void init(tower *tmp)
{
	//printf("%i",tmp[0][0]->getx());
	//~ for (int i = 0; i < r_count; i++)
		//~ for (int j = 0; j < r_count; j++)
			//~ if (tmp[i*r_count+j] != NULL)
				//~ nodemap[i][j].price = -1;
	}



zveno *get_path(int x_s, int y_s, int x_f, int y_f)
{
	//coords First;
	
	
	//printf("%i %i %i %i\n",x_s,y_s,x_f,y_f);
	//стартовый узел
	node start;
	start.x = x_s;
	start.y = y_s;
	start.G = 0;
	
	//~ финишный узел
	node finish;
	finish.x = x_f;
	finish.y = y_f;
	//~ вспомогательный узел
	node vsp = start;
	
	//~ добавление в список открытых
	zveno *open = new zveno();
	open->inf = vsp;
	//print(open);
	
	
	zveno *close = new zveno();
	close->inf = vsp;
	open=pop(open);
	char a[80];
	while ((vsp.x != finish.x || vsp.y != finish.y))// || !empty(open))
{  

		node tmp;


//--------------------------------------------------------------------	

{		
		if (vsp.x < 9)
{
	
		tmp.x = vsp.x + 1;
		tmp.y = vsp.y;

		if  (!find(open,tmp))
{
	
		tmp.parent = new node();

		*tmp.parent = vsp;

		
		tmp.G = tmp.parent->G + 1;
		tmp.H = abs(finish.x -  tmp.x) + abs(finish.y -  tmp.y);
		tmp.F = tmp.G + tmp.H;
		open = pushsort(open,tmp);
}		}

}

//--------------------------------------------------------------------	

{		
		if (vsp.x > 0)
		{
		tmp.x = vsp.x - 1;
		tmp.y = vsp.y;
		
		if  (!find(open,tmp))
{
	tmp.parent = new node();
		*tmp.parent = vsp;
		tmp.G = tmp.parent->G + 1;
		tmp.H = abs(finish.x -  tmp.x) + abs(finish.y -  tmp.y);
		tmp.F = tmp.G + tmp.H;
		open = pushsort(open,tmp);
}		}
		
	}
	
//--------------------------------------------------------------------		

{	
		if (vsp.y < 9)
		{
		tmp.x = vsp.x;
		tmp.y = vsp.y + 1;
		if  (!find(open,tmp))
{
	    tmp.parent = new node();
		*tmp.parent = vsp;
		tmp.G = tmp.parent->G + 1;
		tmp.H = abs(finish.x -  tmp.x) + abs(finish.y -  tmp.y);
		tmp.F = tmp.G + tmp.H;
		open = pushsort(open,tmp);

}		}
		
	}
		
//--------------------------------------------------------------------	
		
{	
		
		if (vsp.y > 0)
		{
		tmp.x = vsp.x;
		tmp.y = vsp.y - 1;
		if  (!find(open,tmp))
{       tmp.parent = new node();
		*tmp.parent = vsp;

		tmp.G = tmp.parent->G + 1;
		tmp.H = abs(finish.x -  tmp.x) + abs(finish.y -  tmp.y);
		tmp.F = tmp.G + tmp.H;
		open = pushsort(open,tmp);

}		}
}

		vsp = open->inf;
		open=pop(open);
		close = push(close,vsp);
}
	
	zveno *parth = new zveno(); 
	node *tmp;
	tmp = &vsp;
	parth->inf = *tmp;
	//~ printf("%i %i %i %i\n",tmp->x,tmp->y,tmp->parent->x,tmp->parent->y);
	while (tmp->parent != NULL)
	{

		tmp = tmp->parent;
		parth = push(parth,*tmp);
		print(parth);		
		
	}
	
	
		char s[80];
		gets(&s[0]);
	
	printf("%s\n","end");
	return parth;
	}
