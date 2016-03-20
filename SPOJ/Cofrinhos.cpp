#include <iostream>
#include <stdio.h>

using namespace std;

int i, n, a, b, t = 1;

int main(void) {
    while(scanf("%d", &n) && n > 0) {
        printf("Teste %d\n", t++);
        int z = 0, j = 0;
        for(i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            z += a; j += b;
            printf("%d\n", (z - j));
        }
        printf("\n");
    }
    return 0;
}
