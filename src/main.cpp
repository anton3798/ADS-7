// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int n = 2; n <= 30; n += 2) {
        Train t_off;
        for (int i = 0; i < n; ++i)
            t_off.addCar(false);
        t_off.getLength();
        int off_steps = t_off.getOpCount();
        Train t_on;
        for (int i = 0; i < n; ++i)
            t_on.addCar(true);
        t_on.getLength();
        int on_steps = t_on.getOpCount();
        int sum_rand = 0;
        for (int trial = 0; trial < 5; ++trial) {
            Train t_rand;
            for (int i = 0; i < n; ++i)
                t_rand.addCar(std::rand() % 2 == 1);
            t_rand.getLength();
            sum_rand += t_rand.getOpCount();
        }
        int avg_rand = sum_rand / 5;
        std::cout << n << "\t" << off_steps << "\t" << on_steps << "\t" << avg_rand << std::endl;
    }
    return 0;
}
