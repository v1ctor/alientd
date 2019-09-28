#pragma once

#ifndef GO_H
#define GO_H

#include <SDL2/SDL.h>
#include "tools.h"
#include "texture.h"

namespace alientd {

class go {
public:
  go(int x_tmp, int y_tmp, Texture* texture);
  ~go() = default;
  void setx(int tmp) { x = tmp; };
  void sety(int tmp) { y = tmp; };
  Texture* getTexture() { return mTexture; };
  int getx() { return x; };
  int gety() { return y; };
  void draw(SDL_Renderer *renderer);
  int x_c, y_c;

protected:
  int x, y;
  Texture* mTexture;
};

}
#endif //__GO_H__
