#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j, p, n, c, matrix[1010][1010], flag[1010], ans;

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d%d", &p, &n, &c) == 3 && !(p == 0 && n == 0 && c == 0)) {
        ans = 0;
        memset(flag, 0, sizeof(flag));
        for(i = 0; i < n; i++) {
            for(j = 0; j < p; j++) {
                scanf("%d", &matrix[i][j]);
                flag[j] += matrix[i][j];
                if(matrix[i][j] == 0 && flag[j] >= c) {
                    ans += 1;
                    flag[j] = 0;
                }
                if(matrix[i][j] == 0) flag[j] = 0;
            }
        }
        for(j = 0; j < p; j++) {
            if(flag[j] >= c) {
                ans += 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
