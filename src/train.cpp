// Copyright 2021 NNTU-CS
#include "train.h"
void Train::addCage(bool light) {
  if (!head) {
    Cage *item = new Cage;
    item->light = light;
    head = item;
    tail = item;
  } else {
    Cage *item = new Cage;
    item->light = light;
    tail->next = item;
    item->prev = tail;
    tail = item;
  }
  tail->next = head;
  head->prev = tail;
}
int Train::getLength() {
  int size = 0;
  Cage * elem = head;
  elem->light = true;
  while (true) {
    while (1) {
      elem = elem->next;
      ++countOp;
      ++helpCount;
      if (elem->light) {
        elem->light = false;
        break;
      }
    }
    size = helpCount;
    while (helpCount) {
      elem = elem->prev;
      ++countOp;
      --helpCount;
    }
    if (!elem->light)
      return size;
  }
}
int Train::getOpCount() {
  return countOp;
}
