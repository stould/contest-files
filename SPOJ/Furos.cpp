#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, i, j, x, y, xx[1010], yy[1010], t = 1;

int dist(int xa, int ya, int xb, int yb) {
    return sqrt(((xa - xb) * (xa - xb)) + ((ya - yb) * (ya - yb)));
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &n) && n > 0) {
        printf("Teste %d\n", (t++));
        double mxdist = 0.0;
        for(i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            xx[i] = x;
            yy[i] = y;
        }
        for(i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) if(i != j) {
                double tmp = dist(xx[i], yy[i], xx[j], yy[j]);
                if(tmp > mxdist) {
                    mxdist = tmp;
                }
             }
        }
        printf("%d\n\n", (int) (mxdist*2) - 2);
    }
    return 0;
}

