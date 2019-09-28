#include "go.h"

#ifndef ENEMY_H
#define ENEMY_H

namespace alientd {

struct zveno {
  node inf;
  zveno *next;
};

class enemy : public go {
public:
  enemy(int x_tmp, int y_tmp, Texture* texture)
      : go(x_tmp, y_tmp, texture) {
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

}

#endif //__ENEMY_H__
