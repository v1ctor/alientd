#include "SDL.h"
//#define true false
//#define false true

class go {
  int x;
  int y;
  SDL_Surface *img;
  // int price;
  // int health;
 public:
  go()  // int x_tmp, int y_tmp, int price_tmp, int health_tmp)
  {
    return;
  };
  ~go() { return; };
  void setx(int tmp) { x = tmp; };
  void sety(int tmp) { y = tmp; };
  int getx() { return x; };
  int gety() { return y; };
};
