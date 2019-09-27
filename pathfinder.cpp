#include "pathfinder.h"
#include <stdio.h>

void add_tower(int i, int j) { nodemap[i][j] = true; }

void del_tower(int i, int j) { nodemap[i][j] = false; }

zveno *get_path(int x_s, int y_s, int x_f, int y_f) {
  // coords First;

  zveno *path = new zveno();
  printf("get_path = %i %i %i %i\n", x_s, y_s, x_f, y_f);
  //стартовый узел
  node start;
  start.x = x_s;
  start.y = y_s;
  start.G = 0;

  //~ финишный узел
  node finish;
  finish.x = x_f;
  finish.y = y_f;
  //~ вспомогательный узел
  node vsp = start;

  //~ открытый список и добавление в список открытых
  zveno *open = new zveno();
  open->inf = vsp;
  // print(open);

  //закрытый список
  zveno *close = new zveno();
  close->inf = vsp;
  open = pop(open);

  //~ цикл главный
  while ((vsp.x != finish.x || vsp.y != finish.y)) // || )
  {
    node tmp;

    //----горизонтали ++ ----------------------------------------------

    if (vsp.x < 9) {
      tmp.x = vsp.x + 1;
      tmp.y = vsp.y;

      if (!find(close, tmp) && !nodemap[tmp.x][tmp.y]) {
        if (!find(open, tmp)) {
          tmp.parent = new node();

          *tmp.parent = vsp;

          tmp.G = tmp.parent->G + 1;
          tmp.H = abs(finish.x - tmp.x) + abs(finish.y - tmp.y);
          tmp.F = tmp.G + tmp.H;
          open = pushsort(open, tmp);
          // printf("open - > %i %i\n",tmp.x,tmp.y);
          // delete tmp.parent;
        }
      }
    }

    //-------горизонтали -- ----------------------------------------------

    if (vsp.x > 0) {
      tmp.x = vsp.x - 1;
      tmp.y = vsp.y;
      if (!find(close, tmp)) {
        if (!find(open, tmp) && !nodemap[tmp.x][tmp.y]) {
          tmp.parent = new node();
          *tmp.parent = vsp;
          tmp.G = tmp.parent->G + 1;
          tmp.H = abs(finish.x - tmp.x) + abs(finish.y - tmp.y);
          tmp.F = tmp.G + tmp.H;
          open = pushsort(open, tmp);
          //	printf("open - > %i %i\n",tmp.x,tmp.y);
          // delete tmp.parent;
        }
      }
    }

    //-------вертикали -- ------------------------------------------------

    if (vsp.y < 9) {
      tmp.x = vsp.x;
      tmp.y = vsp.y + 1;
      if (!find(close, tmp)) {
        if (!find(open, tmp) && !nodemap[tmp.x][tmp.y]) {
          tmp.parent = new node();
          *tmp.parent = vsp;
          tmp.G = tmp.parent->G + 1;
          tmp.H = abs(finish.x - tmp.x) + abs(finish.y - tmp.y);
          tmp.F = tmp.G + tmp.H;
          open = pushsort(open, tmp);
          // printf("open - > %i %i\n",tmp.x,tmp.y);
          // delete tmp.parent;
        }
      }
    }

    //---------вертикали ++ -------------------------------------------

    if (vsp.y > 0) {
      tmp.x = vsp.x;
      tmp.y = vsp.y - 1;
      if (!find(close, tmp)) {
        if (!find(open, tmp) && !nodemap[tmp.x][tmp.y]) {
          tmp.parent = new node();
          *tmp.parent = vsp;

          tmp.G = tmp.parent->G + 1;
          tmp.H = abs(finish.x - tmp.x) + abs(finish.y - tmp.y);
          tmp.F = tmp.G + tmp.H;
          open = pushsort(open, tmp);
          // printf("open - > %i %i\n",tmp.x,tmp.y);
          // delete tmp.parent;
        }
      }
    }

    //----диагонали x+ y- -------------------------------------

    if (vsp.x < 9 && vsp.y > 0) {
      tmp.x = vsp.x + 1;
      tmp.y = vsp.y - 1;
      if (!find(close, tmp) && !nodemap[tmp.x][tmp.y])
        if (tmp.y < 9 && !nodemap[tmp.x][tmp.y + 1])
          if (tmp.x > 0 && !nodemap[tmp.x - 1][tmp.y]) {
            if (!find(open, tmp)) {
              tmp.parent = new node();
              *tmp.parent = vsp;
              tmp.G = tmp.parent->G + 1;
              tmp.H = abs(finish.x - tmp.x) + abs(finish.y - tmp.y);
              tmp.F = tmp.G + tmp.H;
              open = pushsort(open, tmp);
              // printf("open - > %i %i\n",tmp.x,tmp.y);
              // delete tmp.parent;
            }
          }
    }

    //-------диагонали x- y- ----------------------------------------------

    if (vsp.x > 0 && vsp.y > 0) {
      tmp.x = vsp.x - 1;
      tmp.y = vsp.y - 1;
      if (!find(close, tmp)) {
        if (!find(open, tmp) && !nodemap[tmp.x][tmp.y])
          if (tmp.x < 9 && !nodemap[tmp.x + 1][tmp.y])
            if (tmp.y < 9 && !nodemap[tmp.x][tmp.y + 1]) {
              tmp.parent = new node();
              *tmp.parent = vsp;
              tmp.G = tmp.parent->G + 1;
              tmp.H = abs(finish.x - tmp.x) + abs(finish.y - tmp.y);
              tmp.F = tmp.G + tmp.H;
              open = pushsort(open, tmp);
              //	printf("open - > %i %i\n",tmp.x,tmp.y);
              // delete tmp.parent;
            }
      }
    }

    //-------диагонали x+ y+  ------------------------------------------------

    if (vsp.x < 9 && vsp.y < 9) {
      tmp.x = vsp.x + 1;
      tmp.y = vsp.y + 1;
      if (!find(close, tmp)) {
        if (tmp.x > 0 && !nodemap[tmp.x - 1][tmp.y])
          if (tmp.y > 0 && !nodemap[tmp.x][tmp.y - 1])
            if (!find(open, tmp) && !nodemap[tmp.x][tmp.y]) {
              tmp.parent = new node();
              *tmp.parent = vsp;
              tmp.G = tmp.parent->G + 1;
              tmp.H = abs(finish.x - tmp.x) + abs(finish.y - tmp.y);
              tmp.F = tmp.G + tmp.H;
              open = pushsort(open, tmp);
            }
      }
    }

    //---------диагонали х- у+ -------------------------------------------

    if (vsp.x > 0 && vsp.y < 9) {
      tmp.x = vsp.x - 1;
      tmp.y = vsp.y + 1;
      if (!find(close, tmp)) {
        if (tmp.x < 9 && !nodemap[tmp.x][tmp.y - 1])
          if (tmp.y > 0 && !nodemap[tmp.x + 1][tmp.y])
            if (!find(open, tmp) && !nodemap[tmp.x][tmp.y])

            {
              tmp.parent = new node();
              *tmp.parent = vsp;

              tmp.G = tmp.parent->G + 1;
              tmp.H = abs(finish.x - tmp.x) + abs(finish.y - tmp.y);
              tmp.F = tmp.G + tmp.H;
              open = pushsort(open, tmp);
            }
      }
    }

    if (open == NULL && (vsp.x != finish.x || vsp.y != finish.y)) {
      del(open);
      del(close);
      return NULL;
    }

    vsp = open->inf;
    close = push(close, vsp);
    open = pop(open);
  }

  node *tmp;
  tmp = &vsp;
  path->inf = *tmp;
  while (tmp->parent != NULL) {
    tmp = tmp->parent;
    path = push(path, *tmp);
  }

  delete tmp;
  del(open);
  del(close);
  return path;
}
