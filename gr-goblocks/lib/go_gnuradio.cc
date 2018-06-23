#include <iostream>
#include <functional>

#include "go_gnuradio.h"

extern "C" void ExecVoidPtr(unsigned long long ptr) {
    std::function<void()> *f = 
        reinterpret_cast<std::function<void()> *>(ptr);
    (*f)();
}

extern "C" void MyTest() {
    std::cout << "DSFASFSADFFAFAS" << std::endl;
}