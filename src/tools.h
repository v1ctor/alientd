#ifndef TOOLS_H
#define TOOLS_H
#define sqr(x) ((x) * (x))

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include <cmath>

#include "go.h"

namespace alientd {

constexpr int range = 60;
constexpr int r_count = 10;

void DrawIMG(int x, int y, SDL_Texture* texture, SDL_Renderer* renderer);
void DrawIMG(int x, int y, int w, int h, int sx, int sy, SDL_Texture* texture, SDL_Renderer* renderer);

}
#endif //__TOOLS_H__
