#ifndef SPISOK_H
#define SPISOK_H

#include <iostream>
#include <stdio.h>


	struct node
{	int G;
	int H;
	int F; //= H + G;
	int x;
	int y;
	node *parent;
};
	
	
	
struct zveno
{
	node inf;
	zveno *next;
	//zveno *prev;
};


zveno *push(zveno *first, node tmp)
{
	if (empty(first))
	{
		first = new zveno();
		first->inf = tmp;
		//printf("%s\n","first");
	}
	else
	{
		zveno *vsp;
		vsp = new zveno();
		vsp->inf = tmp;
		vsp->next = first;
		first = vsp;
	}
	return first;	
}

zveno *pop(zveno *first)
{
	zveno *vsp;
	if (first->next != NULL)
		vsp=first->next;
	else
		vsp == NULL;
	delete first;
	return vsp;
}



zveno *pushsort(zveno *first, node input)
{	
		if (!first)
	{
		first = new zveno();
		first->inf = input;
		
		}
		else
		{
	zveno *vsp;
	vsp = first;
	zveno *tmp;
	tmp = new zveno();
	tmp->inf = input;
	
		if (vsp->inf.F > input.F)
		{
			tmp->next = vsp;
			//printf("%s\n","first");
			return tmp;	
			
		}
	while(vsp)
	{
		if (vsp->next == NULL)
			{
				vsp->next = tmp;
				return first;
			}
		if (vsp->next->inf.F > input.F)
			{ 
				tmp->next = vsp->next;
				vsp->next = tmp;
				//printf("%s\n","middle");
				//delete tmp;
				return first;
			}
			
			vsp = vsp->next;
	}
	
}
	return first;
}

void print(zveno *first)
{	
	zveno *vsp;
	vsp=first;
	while (vsp != NULL)
           {	printf("%s\n","----------------------------");
			   printf("x,y,F = %i %i %i\n",vsp->inf.x,vsp->inf.y,vsp->inf.F);//,vsp->inf.parent->x,vsp->inf.parent->y); 
			   vsp=vsp->next;
			   //printf("%s\n","----------------------------");
			  }
			  printf("%s\n","end------------------------------");
}

bool find(zveno *first, node input)
{	  
	 zveno *vsp;
	 vsp = first;
	 while (vsp !=NULL)
      {//    printf("%i %i %i %i\n",vsp->inf.x,vsp->inf.y,input.x,input.y);
		 if (vsp->inf.x == input.x && vsp->inf.y == input.y)
		  {
			  //~ printf("%s\n","find");
			  return true;
		  }

		 vsp = vsp->next;
	}
	
	
	return false;
	
	}

bool empty(zveno *first)
{
	if (first == NULL)
		return true;
	return false;
	
}

node get_node(zveno *first)
{
	
	return first->inf;
	
}


void del(zveno *first)
{
	zveno *vsp;
	vsp = first;
	while (vsp)
	{
		first = vsp;
		vsp = vsp->next;
		//~ if (first->inf.parent != NULL)
			//~ delete first->inf.parent;
		delete first;
		
	}
	//~ if (vsp->inf.parent != NULL)
		//~ delete vsp -> inf.parent;
	delete vsp;
	
	
	
}



#endif
