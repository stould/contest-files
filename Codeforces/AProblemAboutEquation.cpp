#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int i, n, b, mx = 0;
double v[110], ex[110];

int main(void) {
    cin >> n >> b;
    for(i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, (int)v[i]);
    }

    for(i = 0; i < n; i++) {
        int tmp = mx - v[i];
        v[i] += tmp;
        ex[i] += tmp;
        b -= tmp;
    }

    if(b < 0) {
        printf("-1"); return 0;
    }

    double ax = (double) ((double)b / (double) n);
    double add = ( (b % n) /  n);

    if(add == ax) add = 0.0;

    for(i = 0; i < n; i++) {
        ex[i] += (double) ax + (double) add;
        printf("%.6f\n", ex[i]);
    }
    return 0;
}
