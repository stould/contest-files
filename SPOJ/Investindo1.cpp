#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, k, ans;

int div_count(int n, int k) {
    if(n > k) {
        div_count(n/2, k);
        div_count(n/2, k);
    } else {
        ans += 1;
    }
}

int main(void) {
    while(scanf("%d%d", &n, &k) == 2 && !(n == 0 && k == 0)) {
        ans = 0;
        div_count(n, k);
        printf("%d\n", ans);
    }
    return 0;
}
