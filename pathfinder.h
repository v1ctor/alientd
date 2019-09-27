#include "SDL.h"
#include "enemy.h"
#include "spisok.h"
#include "tools.h"
#include "tower.h"

#ifndef PATHFINDER_H
#define PATHFINDER_H

static bool nodemap[r_count][r_count] = {};

zveno *get_path(int x_s, int y_s, int x_e, int y_e);
void add_tower(int i, int j);
void del_tower(int i, int j);
#endif
