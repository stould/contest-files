#include<stdio.h>
#include<algorithm>

using namespace std;

#define INF 2000000000
#define MN 1002

int n, m, maze, dp[MN][MN], sum[MN][MN], i, j, k, teste = 1;

int main() {
//    freopen("i.in", "r", stdin);
    while(scanf("%d%d", &n, &m) && !(n == 0 && m == 0)) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                scanf("%d", &maze);
                sum[i][j] = sum[i][j-1]+maze;
                dp[1][j] = sum[1][j];
            }
        }
        for(i = 2; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                dp[i][j] = -INF;
                for(k = 1; k <= m; k++) {
                    if(k <= j) {
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + sum[i][j] - sum[i][k-1]);
                    } else {
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + sum[i][k] - sum[i][j-1]);
                    }
                }
            }
        }
        printf("Teste %d\n%d\n\n", teste++, dp[n][m]);
    }
    return 0;
}
