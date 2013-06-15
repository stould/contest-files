#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int i, j, c, f, n, d, ans, test = 1, dp[55][1010];
pair<int, int> p[55];

int main(void) {
    while(scanf("%d%d", &c, &f) == 2 && !(c == 0 && f == 0)) {
        for(i = 0; i < f; i++) {
            scanf("%d%d", &p[i].first, &p[i].second);
        }
        for(i = 0; i <= c; i++) dp[0][i] = 0;
        for(i = 1; i <= f; i++) {
            for(j = 0; j <= c; j++) {
                if(p[i - 1].first <= j) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i - 1].first] + p[i - 1].second);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        printf("Teste %d\n%d\n\n", test++, dp[f][c]);
    }
    return 0;
}
