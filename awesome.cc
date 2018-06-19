#include <stdio.h>
#include "awesome.h"
#include "try.h"
int main() {
    GoInt s = Init(3.2, 1);
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

    s = Init(2.1, 0);
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
    Gah();
}
