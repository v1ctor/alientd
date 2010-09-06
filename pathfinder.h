#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "SDL.h"
#include "tools.h"
#include "tower.h"
#include "spisok.h"

//~ struct coords 
//~ {	int x;
	//~ int y;
	//~ coords *Next;
//~ };
	//~ 
static node nodemap[r_count][r_count] = {};

void init(tower *tmp);
int get_price(int x_b, int y_b, int x, int y, int x_f, int y_f);
zveno *get_parth(int x_s, int y_s, int x_e, int y_e);

#endif 
