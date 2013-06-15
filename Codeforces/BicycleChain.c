#include <stdio.h>

int i, j, n, m, ans, last, a[60], b[60];

int main(void) {
    scanf("%d", &n); for(i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m); for(i = 0; i < m; i++) scanf("%d", &b[i]);
    ans = last = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(b[j] % a[i] == 0 && b[j] / a[i] > last) {
                ans = 1;
                last = b[j] / a[i];
            } else if(b[j] % a[i] == 0 && b[j] / a[i] == last) {
                ans += 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
