#include <stdio.h>

int n;
long long ans;

int main(void) {
    while(scanf("%d", &n) && n != 0) {
        ans = 0;
        for(int i = 0; i <= n; i++) ans += (long long) (i*i);
        printf("%lld\n", ans);
    }
    return 0;
}
