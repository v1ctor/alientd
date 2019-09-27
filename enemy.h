#include "go.h"

#ifndef ENEMY_H
#define ENEMY_H

struct node {
  int G;
  int H;
  int F; //= H + G;
  int x;
  int y;
  node *parent;
};

struct zveno {
  node inf;
  zveno *next;
};

class enemy : public go {
public:
  enemy(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface *screen)
      : go(x_tmp, y_tmp, dir, screen) {
    speed = 1;
    count = 0;
    health = 150;
    kill = false;
    price = 50;
    flag = true;
  };
  ~enemy() = default;
  void move(int x_f, int y_f);
  bool kill;
  int count;
  int health;
  int price;
  zveno *path;
  bool flag;
  node middle;

protected:
  int speed;

};
#endif //__ENEMY_H__
