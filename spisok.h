#ifndef SPISOK_H
#define SPISOK_H

#include <iostream>
#include <stdio.h>



//~ struct quine
//~ {
	//~ enemy inf;
	//~ quine *next;
//~ };


template <class E> bool empty(E *first)
{
	if (first == NULL)
		return true;
	return false;
	
};

template <class E, class T> E *push(E *first, T tmp)
{
	if (empty(first))
	{
		first = new E();
		first->inf = tmp;
		//printf("%s\n","first");
	}
	else
	{
		E *vsp;
		vsp = new E();
		vsp->inf = tmp;
		vsp->next = first;
		first = vsp;
	}
	return first;	
};

template <class E> E *pop(E *first)
{
	E *vsp;
	if (first->next != NULL)
		vsp=first->next;
	else
		vsp == NULL;
	delete first;
	return vsp;
};



template <class E, class T> E *pushsort(E *first, T input)
{	
		if (!first)
	{
		first = new E();
		first->inf = input;
		
		}
		else
		{
	E *vsp;
	vsp = first;
	E *tmp;
	tmp = new E();
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
};

template <class E> void print(E *first)
{	
	E *vsp;
	vsp=first;
	while (vsp != NULL)
           {	printf("%s\n","----------------------------");
			   printf("x,y,F = %i %i %i\n",vsp->inf.x,vsp->inf.y,vsp->inf.F);//,vsp->inf.parent->x,vsp->inf.parent->y); 
			   vsp=vsp->next;
			   //printf("%s\n","----------------------------");
			  }
			  printf("%s\n","end------------------------------");
};

template <class E, class T> bool find(E *first, T input)
{	  
	 E *vsp;
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
	
	};

//~ node get_node(zveno *first)
//~ {
	//~ 
	//~ return first->inf;
	//~ 
//~ }


template <class E> void del(E *first)
{
	E *vsp;
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
	
	
	
};

#endif
