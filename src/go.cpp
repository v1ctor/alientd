
#include "go.h"

namespace alientd {

  go::go(int x_tmp, int y_tmp, SDL_Texture* texture, SDL_Renderer* renderer) {
  x = x_tmp;
  y = y_tmp;
  mRenderer = renderer;
  img = texture;
  int w, h;
  SDL_QueryTexture(img, NULL, NULL, &w, &h);
  x_c = (int)(x + 0.5 * h);
  y_c = (int)(y + 0.5 * w);
}

void go::draw() {
  DrawIMG(x, y, img, mRenderer);
}

}
