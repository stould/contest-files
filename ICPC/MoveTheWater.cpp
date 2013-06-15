#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    int c[3], a[3], b[3];

    memset(c, 1, sizeof(c));

    while(c[0] != 0) {
        scanf("%d %d %d %d %d %d %d %d %d", &c[0], &c[1], &c[2], &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);

        bool ok = true;

        ok &= (c[0] >= b[0] && c[1] >= b[1] && c[2] >= b[2]);
        int tt = a[0] + a[1] + a[2];
        int ct = b[0] + b[1] + b[2];

        ok &= tt <= ct;

        if(!ok) {
            printf("%d\n", -1);
        } else {

        }

    }

    return 0;
}
