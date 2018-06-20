#include <stdio.h>
#include <iostream>
#include <functional>
#include "awesome.h"
#include "try.h"

void CallbackFunc() {
    printf("I'm a callback!\n");
}

class Test
{
public:
  void callback() {
      printf("I'm a callback from inside a freaking class!\n");
      std::cout << a_ << std::endl;
  }
  
  unsigned long long get_ptr() {
      ptr_ = new std::function<void()>(
          std::bind(&Test::callback, this));
      return reinterpret_cast<unsigned long long>(ptr_);
  }

  Test(std::string a) : a_(a) {}

  ~Test() {
      delete ptr_;
  }

private:
  std::string a_;
  std::function<void()> *ptr_;
};

int main() {
    Test test("hi");
    unsigned long long ptr = test.get_ptr();

    GoInt s = Init(3.2, 1, ptr);
    GoFloat32 data[6] = {77, 12, 5, 99, 28, 23};
    GoFloat32 out[6] = {0, 0, 0, 0, 0, 0};
    GoSlice godata = {data, 6, 6};
    GoSlice goout = {out, 6, 6};
    Work(godata, goout, s);
    for (int i = 0; i < 6; i++){
        printf("%f,", (data)[i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++){
        printf("%f,", (out)[i]);
    }

    printf("\n\n");

    s = Init(2.1, 0, ptr);
    Work(godata, goout, s);
    for (int i = 0; i < 6; i++){
        printf("%f,", (data)[i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++){
        printf("%f,", (out)[i]);
    }

    printf("\n\n");

    Work(godata, goout, s);
    for (int i = 0; i < 6; i++){
        printf("%f,", (data)[i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++){
        printf("%f,", (out)[i]);
    }
    printf("\n");
}
