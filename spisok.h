#ifndef MENU_H
#define MENU_H


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

zveno *push(zveno *first, node tmp);
zveno *pop(zveno *first);
zveno *pushsort(zveno *first, node input);
void print(zveno *first);
bool find(zveno *first, node input);
bool empty(zveno *first);
node get_node(zveno *first);
void del(zveno *first);


#endif
