// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train(): countOp(0), first(nullptr) {}
void Train::addCage(bool light) {
  Cage *cage = new Cage;
  cage -> light = light;
  cage -> prev = nullptr;
  cage -> next = nullptr;
  if (first == nullptr) {
    first = cage;
  } else if (first -> next == nullptr) {
    first -> next = cage;
    cage -> prev = first;
    first -> prev = cage;
    cage -> next = first;
  } else {
    first -> prev -> next = cage;
    cage -> prev = first -> prev;
    first -> prev = cage;
    cage -> next = first;
  }
}

int Train::getlenght() {
  Cage* current = first;
  first -> light = true;
  int lenght = 0;
  countOp = 0;
  while (true) {
    lenght++;
    countOp++;
    int lenghtN;
    current = current -> next;
    if (current -> light) {
      current -> light = false;
      lenghtN = lenght;
      for (lenghtN; lenghtN > 0; lenghtN--) {
        current = current -> prev;
        countOp++;
      }
      if (!current -> light) {
        return lenght;
      }
      lenght = lenghtN;
    }
  }
}

int Train::getOpCount() {
 return countOp;
}
