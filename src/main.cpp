// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  const int N = 60;

  Train trainOn;
  for (int i = 0; i < N; ++i)
    trainOn.addCar(true);
  std::cout << trainOn.getLength()
          << " "<< trainOn.getOpCount() << std::endl;

  Train trainOff;
  for (int i = 0; i < N; ++i)
    trainOff.addCar(false);
  std::cout << trainOff.getLength()
          << " "<< trainOff.getOpCount() << std::endl;

  Train trainRand;
  for (int i = 0; i < N; ++i)
    trainRand.addCar(std::rand() % 2 == 1);
  std::cout << trainRand.getLength()
          << " "<< trainRand.getOpCount() << std::endl;
  return 0;
}
