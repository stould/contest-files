#include <stdio.h>

int i, n;
long s;

int main(void) {
    while(scanf("%d", &n) && n > 0) {
        s = 0L;
        for(i = 1; i <= n; i++) {
            s += i*i;
        }
        printf("%ld\n", s);
    }
    return 0;
}
