#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, t, n, tmp, sum;

int main(void) {
    while(scanf("%d%d", &t, &n) == 2 && !(t == 0 && n == 0)) {
        sum = 0;
        for(i = 0; i < t; i++) {
            scanf("%*s%d", &tmp);
            sum += tmp;
        }
        printf("%d\n", (int) (((n * 3) - sum)));
    }
    return 0;
}
