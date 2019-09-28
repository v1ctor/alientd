#ifndef SPISOK_H
#define SPISOK_H

namespace alientd {


template <class E> bool empty(E *first) {
  if (first == nullptr)
    return true;
  return false;
};

template <class E, class T> E *push(E *first, T tmp) {
  if (empty(first)) {
    first = new E();
    first->inf = tmp;
  } else {
    E *vsp;
    vsp = new E();
    vsp->inf = tmp;
    vsp->next = first;
    first = vsp;
  }
  return first;
};

template <class E> E *pop(E *first) {
  E *vsp;
  if (first->next != nullptr)
    vsp = first->next;
  else
    vsp = nullptr;
  delete first;
  return vsp;
};

template <class E, class T> E *pushsort(E *first, T input) {
  if (!first) {
    first = new E();
    first->inf = input;

  } else {
    E *vsp;
    vsp = first;
    E *tmp;
    tmp = new E();
    tmp->inf = input;

    if (vsp->inf.F > input.F) {
      tmp->next = vsp;
      return tmp;
    }
    while (vsp) {
      if (vsp->next == nullptr) {
        vsp->next = tmp;
        return first;
      }
      if (vsp->next->inf.F > input.F) {
        tmp->next = vsp->next;
        vsp->next = tmp;
        return first;
      }

      vsp = vsp->next;
    }
  }
  return first;
};

template <class E> void print(E *first) {
  E *vsp;
  vsp = first;
  while (vsp != nullptr) {
    vsp = vsp->next;
  }
};

template <class E, class T> bool find(E *first, T input) {
  E *vsp;
  vsp = first;
  while (vsp != nullptr) {
    if (vsp->inf.x == input.x && vsp->inf.y == input.y) {
      return true;
    }

    vsp = vsp->next;
  }

  return false;
};

template <class E> void del(E *first) {
  E *vsp;
  vsp = first;
  while (vsp) {
    first = vsp;
    vsp = vsp->next;
    delete first;
  }
  delete vsp;
};

}
#endif
