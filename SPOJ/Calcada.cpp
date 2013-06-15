#include <stdio.h>
#include <stdlib.h>

int T, aa, bb, cc, dd, ans;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main(void) {
    scanf("%d", &T);
    for(; T > 0; T--) {
        scanf("%d%d%d%d", &aa, &bb, &cc, &dd);
        printf("%d\n", gcd(abs(aa - cc), abs(bb - dd)) + 1);
    }
    return 0;
}
