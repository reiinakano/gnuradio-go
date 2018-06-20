#include <stdio.h>
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
  }
  
  unsigned long long get_ptr() {
      ptr = new std::function<void()>(
          std::bind(&Test::callback, this));
      return reinterpret_cast<unsigned long long>(ptr);
  }

  ~Test() {
      delete ptr;
  }

private:
  std::function<void()> *ptr;
};

int main() {
    Test test;
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
