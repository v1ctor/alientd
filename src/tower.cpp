
#include "tower.h"
#include "tools.h"

namespace alientd {

bool tower::detect(enemy *tmp) {
  if (tmp == nullptr)
    return false;

  int w, h;
  SDL_QueryTexture(tmp->getimg(), NULL, NULL, &w, &h);
  int x_tmp = tmp->getx();
  int y_tmp = tmp->gety();
  int h_tmp = h;

  if (sqrt(sqr(x_tmp + h_tmp - x_c) + sqr(y_tmp + h_tmp - y_c)) < radius ||
      sqrt(sqr(x_tmp + h_tmp - x_c) + sqr(y_tmp - y_c)) < radius ||
      sqrt(sqr(x_tmp - x_c) + sqr(y_tmp + h_tmp - y_c)) < radius ||
      sqrt(sqr(x_tmp - x_c) + sqr(y_tmp - y_c)) < radius)
    return true;

  return false;
}

} // namespace alientd
