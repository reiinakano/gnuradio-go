#include <iostream>
#include <functional>

#include "try.h"

extern "C" void No(unsigned long long ptr) {
    std::function<void()> *f = 
        reinterpret_cast<std::function<void()> *>(ptr);
    (*f)();
}
