
#include "enemy.h"
#include "list.h"
#include "pathfinder.h"

namespace alientd {

void enemy::move(int x_f, int y_f) {
  x_c = (int)(x + 0.5 * range);
  y_c = (int)(y + 0.5 * range);

  if (health > 0) {
    if (flag) {
      path = get_path((int)(x / range), (int)(y / range), (int)(x_f / range),
                      (int)(y_f / range));
      flag = false;
      path = pop(path);
      middle = path->inf;
      path = pop(path);
    }

    if (abs(x - middle.x * range) >= speed ||
        abs(y - middle.y * range) >= speed) {
      if (x < middle.x * range)
        x += speed;
      if (x > middle.x * range)
        x -= speed;
      if (y < middle.y * range)
        y += speed;
      if (y > middle.y * range)
        y -= speed;

    } else {
      middle = path->inf;
      path = pop(path);
    }

  } else {
    kill = true;
    del(path);
  }

  return;
}

} // namespace alientd
