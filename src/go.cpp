
#include "go.h"

namespace alientd {

go::go(int x_tmp, int y_tmp, Texture* texture) {
  x = x_tmp;
  y = y_tmp;
  mTexture = texture;
  x_c = (int)(x + 0.5 * texture->getHeight());
  y_c = (int)(y + 0.5 * texture->getWidth());
}

void go::draw(SDL_Renderer *renderer) { mTexture->render(renderer, x, y); }

} // namespace alientd
