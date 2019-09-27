#include "tools.h"

void DrawIMG(int x, int y, SDL_Surface *img, SDL_Surface *screen) {
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 255, 0));
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_BlitSurface(img, NULL, screen, &dest);
}

void DrawIMG(int x, int y, int w, int h, int sx, int sy, SDL_Surface *img,
             SDL_Surface *screen) {
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 255, 0));
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;

  SDL_Rect src;
  src.x = sx;
  src.y = sy;
  src.w = w;
  src.h = h;

  SDL_BlitSurface(img, &src, screen, &dest);
}
