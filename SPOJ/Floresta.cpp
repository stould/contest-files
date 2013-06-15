#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;

int main(void) {
    scanf("%d", &n);
    int ans = 0;
    for(int a = 2; 2 * a * a - 2 * a + 1 <= n; a++) {
        if((n+a-1) % (2*a-1) == 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
