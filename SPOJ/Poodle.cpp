#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, n, p;

int main(void) {
    while(scanf("%d%d", &n, &p) == 2 && !(n == 0 && p == 0)) {
        int div = (int) n / p;
        if(n % p > 0) div++;
        printf("P");
        if(div > 6) {
            for(i = 0; i <= div - 5 && i + 5 <= 20; i++) {
                printf("o");
            }
        } else {
            printf("oo");
        }
        printf("dle\n");

    }
    return 0;
}
