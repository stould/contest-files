#include <stdio.h>

int h1, h2, m1, m2;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int main(void) {
    while(scanf("%d%d%d%d", &h1, &m1, &h2, &m2)) {
        if(!h1 && !m1 && !h2 && !m2) break;
        int a = (h2*60) + m2;
        int b = (h1*60) + m1;

        if(b > a) {
            swap(a, b);
            b += 1440;
        }
        printf("%d\n", abs(a - b));
    }
    return 0;
}
