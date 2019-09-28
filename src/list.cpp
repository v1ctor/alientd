#include "list.h"

namespace alientd {

zveno *push(zveno *first, node tmp) {
  if (empty(first)) {
    first = new zveno();
    first->inf = tmp;
  } else {
    zveno *vsp;
    vsp = new zveno();
    vsp->inf = tmp;
    vsp->next = first;
    first = vsp;
  }
  return first;
}

zveno *pop(zveno *first) {
  zveno *vsp;
  if (first->next != nullptr)
    vsp = first->next;
  else
    vsp = nullptr;
  delete first;
  return vsp;
}

zveno *pushsort(zveno *first, node input) {
  if (!first) {
    first = new zveno();
    first->inf = input;

  } else {
    zveno *vsp;
    vsp = first;
    zveno *tmp;
    tmp = new zveno();
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
}

bool find(zveno *first, node input) {
  zveno *vsp;
  vsp = first;
  while (vsp != nullptr) {
    if (vsp->inf.x == input.x && vsp->inf.y == input.y) {
      return true;
    }

    vsp = vsp->next;
  }

  return false;
}

bool empty(zveno *first) {
  if (first == nullptr)
    return true;
  return false;
}

node get_node(zveno *first) { return first->inf; }

void del(zveno *first) {
  zveno *vsp;
  vsp = first;
  while (vsp) {
    first = vsp;
    vsp = vsp->next;
    delete first;
  }
  delete vsp;
}

} // namespace alientd
