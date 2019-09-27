#include <SDL2/SDL.h>
#include "tools.h"

#ifndef GO_H
#define GO_H

namespace alientd {

class go {
public:
  go(int x_tmp, int y_tmp, SDL_Texture* texture, SDL_Renderer* renderer);
  ~go() = default;
  void setx(int tmp) { x = tmp; };
  void sety(int tmp) { y = tmp; };
  SDL_Texture *getimg() { return img; };
  int getx() { return x; };
  int gety() { return y; };
  void draw();
  int x_c, y_c;

protected:
  int x, y;
  SDL_Texture *img;
  SDL_Renderer *mRenderer;
};

}
#endif //__GO_H__
