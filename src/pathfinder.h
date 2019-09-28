#include "SDL.h"
#include "enemy.h"
#include "list.h"
#include "tools.h"
#include "tower.h"

#ifndef PATHFINDER_H
#define PATHFINDER_H

namespace alientd {

struct node {
  int G;
  int H;
  int F; //= H + G;
  int x;
  int y;
  node *parent;
};


static bool nodemap[r_count][r_count] = {};

zveno *get_path(int fromX, int fromY, int toX, int toY);
void add_tower(int i, int j);
void del_tower(int i, int j);

}
#endif
