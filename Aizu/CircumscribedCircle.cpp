#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef long double ld;

ld x1, x2, x3, y1, y2, y3;

int ans;

struct Point {
    ld x, ld y;

    Point() { }
    Point(ld a, ld b) {
        x = a;
        y = b;
    }
    void move(ld a, ld b) {
        x = a;
        y = b;
    }
};

int main(void) {
    int N;
    scanf("%d", &N);

    while(N > 0) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        p1 = Point((ld)(x1 + x2) / 2, (ld)(y1 + y2) / 2);
        p2 = Point((ld)(x1 + x3) / 2, (ld)(y1 + y3) / 2);
        p2 = Point((ld)(x2 + x3) / 2, (ld)(y2 + y3 / 2));



        N--;
    }

    return 0;
}

