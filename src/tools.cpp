#include "tools.h"

namespace alientd {

void DrawIMG(int x, int y, SDL_Texture *texture, SDL_Renderer *renderer) {
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

void DrawIMG(int x, int y, int w, int h, int sx, int sy, SDL_Texture *texture,
             SDL_Renderer *renderer) {
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;

  SDL_Rect src;
  src.x = sx;
  src.y = sy;
  src.w = w;
  src.h = h;

  SDL_RenderCopy(renderer, texture, &src, &dest);
}

} // namespace alientd
