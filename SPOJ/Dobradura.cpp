#include <stdio.h>

int n, t = 1;

int main(void) {
    while(scanf("%d", &n) && n != -1) {
        printf("Teste %d\n%d\n", t, (1 + (1 << n))*(1 + (1 << n))); t++;
    }
    return 0;
}
