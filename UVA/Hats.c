#include <stdio.h>
#include <stdlib.h>

int T, N;

int d[13] = {0, 0, 1, 2, 9, 44, 265, 1854, 14833, 133496, 1334961, 14684570, 176214841};
int f[13] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main(void) {
    scanf("%d", &T);
    for( ; T-- ; ) {
        scanf("%d", &N);
        printf("%d/%d\n", d[N], f[N]);
    }
    return 0;
}
