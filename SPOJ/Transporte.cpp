#include <stdio.h>
#include <stdlib.h>

int a, b, c, x, y, z;

int main(void) {
    scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
    printf("%d\n", (y/b)*(x/a)*(z/c));
    return 0;
}
