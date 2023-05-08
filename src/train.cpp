// Copyright 2021 NNTU-CS
#include "train.h"
void Train::addCage(bool light)
{
  if (head == 0) {
    Cage *item = new Cage;
    item->light = light;
    head = tail = item;
  }
  else {
    Cage *item = new Cage;
    item->light = light;
    tail->next = item;
    item->prev = tail;
    tail = item;
  }
  tail->next = head;
  head->prev = tail;
}
int Train::getLength()
{
  int size = 0;
  Cage * elem = head;
  elem->light = true;
  while (true) {
    while (true) {
      elem = elem->next;
      ++countOp;
      ++helpCount;
      if (elem->light == true) {
        elem->light = false;
        break;
      }
    }
    size = helpCount;
    while (helpCount != 0) {
      elem = elem->prev;
      --helpCount;
      ++countOp;
    }
    if (elem->light != false) {
      return size;
    }
  }
  return 0;
}
int Train::getOpCount()
{
  return countOp;
}
