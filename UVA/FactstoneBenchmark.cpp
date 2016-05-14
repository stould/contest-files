#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int y, f[14], m[2170];

void func1() {
    f[0] = f[1] = 1;
    for(int i = 2; i <= 12; i++) {
        f[i] = i * f[i - 1];
    }
}
void func2() {
    int base = 4;
    for(int i = 1960; i <= 2160; i += 10) {
        for(i)
        m[i] = base;
        base <<= 1;
    }
}
int main(void) {
    func1(); func2();
    for(; ~scanf("%d", &y) && y > 0; ) {

    }
    return 0;
}
