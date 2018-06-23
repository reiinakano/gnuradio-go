#include <iostream>
#include <functional>

#include "go_gnuradio.h"

extern "C" void ExecVoidPtr(unsigned long long ptr) {
    std::function<void()> *f = 
        reinterpret_cast<std::function<void()> *>(ptr);
    (*f)();
}

extern "C" void _ExecSetOutputMultiple(unsigned long long ptr, int output_multiple) {
    std::function<void(int)> *f = 
        reinterpret_cast<std::function<void(int)> *>(ptr);
    (*f)(output_multiple);
}

extern "C" void MyTest() {
    std::cout << "DSFASFSADFFAFAS" << std::endl;
}