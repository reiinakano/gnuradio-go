#include <iostream>
#include <functional>

#include "go_gnuradio.h"

extern "C" void ExecVoidPtr(unsigned long long ptr) {
    std::function<void()> *f = 
        reinterpret_cast<std::function<void()> *>(ptr);
    (*f)();
}

extern "C" int _ExecOutputMultiple(unsigned long long ptr) {
    std::function<int()> *f = 
        reinterpret_cast<std::function<int()> *>(ptr);
    return (*f)();
}

extern "C" void _ExecSetOutputMultiple(unsigned long long ptr, int output_multiple) {
    std::function<void(int)> *f = 
        reinterpret_cast<std::function<void(int)> *>(ptr);
    (*f)(output_multiple);
}

extern "C" unsigned int _ExecHistory(unsigned long long ptr) {
    std::function<unsigned int()> *f = 
        reinterpret_cast<std::function<unsigned int()> *>(ptr);
    return (*f)();
}

extern "C" void _ExecSetHistory(unsigned long long ptr, unsigned int history) {
    std::function<void(int)> *f = 
        reinterpret_cast<std::function<void(int)> *>(ptr);
    (*f)(history);
}

extern "C" void MyTest() {
    std::cout << "DSFASFSADFFAFAS" << std::endl;
}