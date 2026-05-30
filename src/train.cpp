// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
      first = newCar;
      first->next = first;
      first->prev = first;
    } else {
      Car* last = first->prev;
      newCar->next = first;
      newCar->prev = last;
      last->next = newCar;
      first->prev = newCar;
  }
}

int Train::getLength() {
  Car* start = first;
  start->light = true;
  while (true) {
    Car* cur = start;
    int d = 0;
      do {
        cur = cur->next;
        ++countOp;
        ++d;
      } while (!cur->light);
      cur->light = false;
      for (int i = 0; i < d; ++i) {
        cur = cur->prev;
        ++countOp;
        }
      if (!start->light) {
        return d;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
