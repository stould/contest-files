#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int d, l, k, p;

int main(void) {
    scanf("%d%d%d%d", &d, &l, &k, &p);
    printf("%d\n", (d * k) + ((d / l) * p));
    return 0;
}
