#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max(int a, int b) { return a > b ? a: b;}

int t, n, dp[110][110], mem[110][110];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &t);
    int test = 1;
    for(; t > 0; t--) {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp)); memset(mem, 0, sizeof(mem));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                scanf("%d", &mem[i][j]);
            }
        }
        int ind = 1;
        for(int i = n; i < n + n; i++) {
            for(int j = 0; j < n - ind; j++) {
                scanf("%d", &mem[i][j]);
            }
            ind++;
        }
        dp[0][0] = mem[0][0];
        for(int i = 1; i <= n*2-1; i++) {
            for(int j = 0; j <= n*2-1; j++) {
                dp[i][j] = max(dp[i - 1][j] + mem[i][j], dp[i - 1][j - 1] + mem[i][j]);
            }
        }
        for(int i = 0; i <= n; i++) {
            printf("%d ", dp[2*n-1][i]);
        }
        printf("\n");
        //printf("Case %d: %d\n", test++, dp[n][0]);
    }
    return 0;
}
