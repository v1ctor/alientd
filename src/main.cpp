#include <SDL2_ttf/SDL_ttf.h>

#include <string>

#include "enemy.h"
#include "list.h"
#include "pathfinder.h"
#include "tools.h"
#include "tower.h"
#include "texture.h"

using namespace alientd;

SDL_Window *screen;
Texture back, alien, towerimg, bullet, allow, deny, startimg, menu;

int money = 500;


struct quine {
  enemy *inf;
  quine *next;
  quine *prev;
};

quine *ufo;
tower *twr[r_count][r_count] = {};

int count = 0;
int count2 = 0;
int x_vsp = -1, y_vsp = -1;
bool start = false;
SDL_Color clr; // = {255,255,255,0};
SDL_Rect dest; // = {620, 0,0,0};
std::string fontname = "font/seed_cyr_medim.ttf";
SDL_Renderer *renderer = nullptr;

// void print_ttf(std::string message, std::string fontName, int size,
//                SDL_Color color, SDL_Rect dest) {
//   TTF_Font *font = TTF_OpenFont(fontName.c_str(), size);
//   if (!font)
//     printf("TTF_OpenFont: %s\n", TTF_GetError());
//   SDL_Surface *surfaceMessage =
//       TTF_RenderText_Blended(font, message.c_str(), color);
//   SDL_Texture *result = SDL_CreateTextureFromSurface(
//       renderer, surfaceMessage); // now you can convert it into a texture
//   SDL_RenderCopy(renderer, result, NULL, &dest);
//   SDL_FreeSurface(surfaceMessage);
// }

void InitImages() {
  back.loadFromFile(renderer, "img/background.png");
  menu.loadFromFile(renderer, "img/menu.png");
  towerimg.loadFromFile(renderer, "img/tower.png");
  alien.loadFromFile(renderer, "img/ufo.png");
  allow.loadFromFile(renderer, "img/allow.png");
  deny.loadFromFile(renderer, "img/deny.png");
  bullet.loadFromFile(renderer, "img/bullet.png");
}

void CheckMoney() {
  clr = {0, 255, 240, 0};
  dest = {620, 60, 0, 0};

  DrawIMG(dest.x - 20, dest.y, 200, 22, 0, 0, menu, renderer);

  // print_ttf("Money:", fontname, 20, clr, dest);
  dest = {700, 60, 0, 0};

  char *buff = new char();
  sprintf(buff, "%i", money);
  // print_ttf(buff, fontname, 20, clr, dest);
  delete buff;
}

void Shot(tower *tmp) {
  //~ Если обнаружен враг
  if (tmp->attacked != nullptr) {
    //Считывание координат врага
    tmp->x_bull_end = tmp->attacked->x_c;
    tmp->y_bull_end = tmp->attacked->y_c;

    //Отрисовка фона и башни
    int w, h;
    SDL_QueryTexture(bullet, NULL, NULL, &w, &h);
    DrawIMG(tmp->x_bull, tmp->y_bull, h, w, tmp->x_bull, tmp->y_bull, back,
            renderer);
    DrawIMG(tmp->getx(), tmp->gety(), towerimg, renderer);

    //Расстояние по х и у от пули до врага
    int dx = tmp->x_bull_end - tmp->x_bull;
    int dy = tmp->y_bull_end - tmp->y_bull;

    // if(abs(dx) < (int) tmp->attacked->getimg()->h / 2 && abs(dy) < (int)
    // tmp->attacked->getimg()->h / 2 )
    if (abs(dx) < tmp->speed && abs(dy) < tmp->speed) {
      // printf("%i %i,",tmp->x_bull,tmp->y_bull);
      tmp->attacked->health -= tmp->power;
      money += 5;

      CheckMoney();

      tmp->x_bull = tmp->x_c;
      tmp->y_bull = tmp->y_c;
      return;
    } else {
      //Коэффициэнт подобия
      double v = tmp->speed / sqrt(sqr(dx) + sqr(dy));

      //Скорости х и у
      int speedx = (int)(v * dx);
      int speedy = (int)(v * dy);

      //перемещение
      tmp->x_bull += speedx;
      tmp->y_bull += speedy;

      //Отрисовка пули
      DrawIMG(tmp->x_bull, tmp->y_bull, bullet, renderer);
    }
  }

  return;
}

void Lighting(int x, int y) {
  if (twr[x][y] == nullptr && money < 100) {
    DrawIMG(x * range, y * range, deny, renderer);
  }

  else
    DrawIMG(x * range, y * range, allow, renderer);
}

void DrawTowers() {
  if (count2 == 20) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        //~ Если башня существует
        if (twr[i][j] != nullptr) {
          twr[i][j]->attack();

          if (twr[i][j]->attacked != nullptr)

            // printf("%i\n",attacked->health);
            if (twr[i][j]->attacked->kill ||
                !twr[i][j]->detect(twr[i][j]->attacked)) {
              int w, h;
              SDL_QueryTexture(bullet, NULL, NULL, &w, &h);
              DrawIMG(twr[i][j]->x_bull, twr[i][j]->y_bull, h, w,
                      twr[i][j]->x_bull, twr[i][j]->y_bull, back, renderer);
              DrawIMG(twr[i][j]->getx(), twr[i][j]->gety(), towerimg, renderer);
              twr[i][j]->attacked = nullptr;
            }

          if (twr[i][j]->attacked == nullptr) {
            quine *vsp = ufo;
            while (vsp) {
              if (twr[i][j]->detect(vsp->inf))
                twr[i][j]->attacked = vsp->inf;
              vsp = vsp->next;
            }
            delete vsp;
          }

          Shot(twr[i][j]);
        }
      }
    }
    count2 = 0;
  }
  count2++;
}

void DrawEnemy() {
  quine *vsp = ufo;
  while (vsp) {
    int x_twr = (int)vsp->inf->getx() / range;
    int y_twr = (int)vsp->inf->gety() / range;

    int w, h;
    SDL_QueryTexture(vsp->inf->getimg(), NULL, NULL, &w, &h);
    DrawIMG(vsp->inf->getx(), vsp->inf->gety(), h, w, vsp->inf->getx(),
            vsp->inf->gety(), back, renderer);
    if ((x_twr == 9 && y_twr == 0) || vsp->inf->kill) {
      if (vsp == ufo) {
        ufo = vsp->next;
        vsp = vsp->next;
        delete vsp->prev;
        continue;
      }

      if (vsp->next == nullptr) {
        delete vsp;
        return;
      }

      vsp->next->prev = vsp->prev;
      vsp->prev = vsp->next;
    }

    if (twr[x_twr][y_twr] != nullptr)
      twr[x_twr][y_twr]->draw();
    if (x_twr < 9 && twr[x_twr + 1][y_twr] != nullptr)
      twr[x_twr + 1][y_twr]->draw();
    if (y_twr < 9 && twr[x_twr][y_twr + 1] != nullptr)
      twr[x_twr][y_twr + 1]->draw();
    if (x_twr < 9 && y_twr < 9 && twr[x_twr + 1][y_twr + 1] != nullptr)
      twr[x_twr + 1][y_twr + 1]->draw();

    if (vsp->inf->count == 16) {
      vsp->inf->move(540, 0);

      vsp->inf->count = 0;
    }

    vsp->inf->draw();
    vsp->inf->count++;

    vsp = vsp->next;
  }
  delete vsp;
  return;
}

void DrawScene() {
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer);
  DrawTowers();
  if (start) {
    DrawEnemy();
  }
  SDL_RenderPresent(renderer);
}

void CreateTower(int x, int y) {
  add_tower(x, y);
  DrawIMG(x * range, y * range, range, range, x * range, y * range, back,
          renderer);
  twr[x][y] = new tower(x * range, y * range, towerimg, renderer);
  twr[x][y]->draw();

  quine *vsp = ufo;
  while (vsp)
    vsp->inf->flag = true;
  delete vsp;
  money -= 100;
  CheckMoney();
}

void DeleteTower(int x, int y) {
  DrawIMG(x * range, y * range, range, range, x * range, y * range, back,
          renderer);
  twr[x][y] = nullptr;
  del_tower(x, y);

  quine *vsp = ufo;
  while (vsp)
    vsp->inf->flag = true;
  delete vsp;

  money += 50;

  CheckMoney();
}

void end() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(screen);

  TTF_Quit();
  SDL_Quit();
  IMG_Quit();
}

bool initSDL() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return false;
  }

  if (TTF_Init() == -1) {
    return false;
  }

  int flags = IMG_INIT_JPG | IMG_INIT_PNG;
  int initted = IMG_Init(flags);
  if ((initted & flags) != flags) {
    return false;
  }

  screen =
      SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
  if (screen == nullptr) {
    return false;
  }
  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
  return renderer != nullptr;
}

void pressButton(int screenX, int screenY, int button) {
  int x_tmp = screenX / range;
  int y_tmp = screenY / range;
  if (twr[x_tmp][y_tmp] == nullptr && screenX <= 600 && button == 1 &&
      money - 100 >= 0)
    CreateTower(x_tmp, y_tmp);
  if (twr[x_tmp][y_tmp] != nullptr && screenX <= 600 && button == 3)
    DeleteTower(x_tmp, y_tmp);
  if (!start && x_tmp > 9 && x_tmp < 14 && y_tmp == 0) {
    start = true;
    int w, h;
    SDL_QueryTexture(alien, NULL, NULL, &w, &h);
    enemy *tmp = new enemy((int)(0 * range + (range - w) / 2),
                           (int)(9 * range + (range - h) / 2), alien, renderer);
    ufo = new quine();
    ufo->inf = tmp;
  }
}

void mouseMove(int x, int y) {
  if (x_vsp != x || y_vsp != y) {
    DrawIMG(x_vsp * range, y_vsp * range, range, range, x_vsp * range,
            y_vsp * range, back, renderer);
    if (twr[x_vsp][y_vsp] != nullptr)
      twr[x_vsp][y_vsp]->draw();
  }

  if (x < 10) {
    Lighting(x, y);
    x_vsp = x;
    y_vsp = y;
  }
}

bool handleEvent() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      return false;
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        return false;
      }
      break;
    case SDL_MOUSEBUTTONDOWN:
      pressButton(event.button.x, event.button.y, event.button.button);
      break;
    case SDL_MOUSEMOTION:
      int x, y;
      SDL_GetMouseState(&x, &y);
      x = (int)x / range;
      y = (int)y / range;
      mouseMove(x, y);
      break;
    }
  }
  return true;
}

void runMainLoop() {
  bool done = false;
  while (!done) {
    if (!handleEvent()) {
      done = true;
    }
    DrawScene();
  }
}

void initGameState() {
  InitImages();
  DrawIMG(0, 0, back, renderer);
  DrawIMG(600, 0, menu, renderer);
  clr = {255, 255, 255, 0};
  dest = {620, 0, 0, 0};
  // print_ttf("START", fontname, 60, clr, dest);
  CheckMoney();
}

int main(int argc, char **argv) {

  if (!initSDL()) {
    return -1;
  }

  runMainLoop();

  end();
  return 0;
}
