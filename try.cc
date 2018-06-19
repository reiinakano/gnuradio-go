#include <iostream>
#include "try.h"
extern "C" int Gah(int x) {
    std::cout << "yo" << std::endl;
    return x;
}
