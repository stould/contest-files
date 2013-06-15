#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int d, vf, vg;
bool got;

int main(void) {
    while(scanf("%d%d%d", &d, &vf, &vg) == 3) {
        got = false;
        double low = 1.0, high = 12.0, mid;

        for(int x = 0; x < 100; x++) {
            mid = (double) (low + high) / 2.0;

            double tl = (double) (vf / (hypot(0, mid)));
            double tg = (double) (vg / (hypot(d, mid)));

            if(tg >= tl) {
                got = true;
                high = mid;
            } else {
                low = mid;
            }
        }
        if(got) {
            puts("S");
        } else {
            puts("N");
        }
    }
    return 0;
}
