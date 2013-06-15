#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a, b, c, d, e, f;
double x, y;

int main(void) {
    for(; ~scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f); ) {
        for(x = -1000.0; x <= 1000.0; x++) {
            for(y = -1000.0; y <= 1000.0; y++) {
                int fpa = (int) (a * x);
                int spa = (int) (b * y);
                int fpb = (int) (d * x);
                int spb = (int) (e * y);

                if((long long) fpa + (long long) spa == (long long) c && (long long) fpb + (long long) spb == (long long) f) {
                    goto end;
                }
            }
        }
        end:
        printf("%.3f %.3f\n", x, y);
    }
}
