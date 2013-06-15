#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int test, n, i, ans, alive[1010];
char s[1010];

int main(void) {
    scanf("%d", &test);
    for( ; test-- > 0; ) {
        scanf("%d%s", &n, s);
        ans = 0;
        memset(alive, 0, sizeof(alive));
        for(i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(i == 0) {
                    alive[i] = alive[i + 1] = 1;
                } else if(i == n - 1) {
                    alive[i] = alive[i - 1] = 1;
                } else {
                    alive[i] = alive[i - 1] = alive[i + 1] = 1;
                }
            }
        }
        for(i = 0; i < n; i++) if(alive[i] == 0) ans += 1;
        printf("%d\n", ans);
    }
    return 0;
}
