
#include "tower.h"
#include "tools.h"

void tower::attack() {}

bool tower::detect(enemy *tmp) {
  if (tmp == NULL)
    return false;

  int x_tmp = tmp->getx();
  int y_tmp = tmp->gety();
  int h_tmp = tmp->getimg()->h;

  if (sqrt(sqr(x_tmp + h_tmp - x_c) + sqr(y_tmp + h_tmp - y_c)) < radius ||
      sqrt(sqr(x_tmp + h_tmp - x_c) + sqr(y_tmp - y_c)) < radius ||
      sqrt(sqr(x_tmp - x_c) + sqr(y_tmp + h_tmp - y_c)) < radius ||
      sqrt(sqr(x_tmp - x_c) + sqr(y_tmp - y_c)) < radius)
    return true;

  return false;
}
