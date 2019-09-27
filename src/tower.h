#ifndef TOWER_H
#define TOWER_H
#include "enemy.h"
#include "go.h"

namespace alientd {

class tower : public go {
public:
  tower(int x_tmp, int y_tmp, SDL_Surface *dir, SDL_Surface *screen)
      : go(x_tmp, y_tmp, dir, screen) {
    radius = (int)1 * range + 0.5 * range;
    attacked = nullptr;
    speed = 5;
    x_bull_end = -1;
    y_bull_end = -1;

    x_bull = x_c;
    y_bull = y_c;
    power = 5;
  }

  ~tower() = default;
  void attack(); // enemy *tmp);//int x, int y);
  bool detect(enemy *tmp);
  enemy *attacked;
  int x_bull, y_bull, x_bull_end, y_bull_end;
  int radius;
  int power;
  int speed;

protected:
  // int x_prev,y_prev;
};

}
#endif //__ENEMY_H__
