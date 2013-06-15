#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int l, c, r1, r2;
int main(void) {
    while(scanf("%d%d%d%d", &l, &c, &r1, &r2) && !(l+c+r1+r2==0)) {
        int d1 = r1 * 2;
        int d2 = r2 * 2;

        if(d1 + d2 <= l && d1 + d2 <= c){
            puts("S"); continue;
        }

        if(d1 <= l && d2 <= c && d1 <= c && d2 <= l && hypot(r1 - (c - r2), r1 - (l - r2)) >= r1+r2) {
            puts("S");
        } else {
            puts("N");
        }
    }
    return 0;
}

