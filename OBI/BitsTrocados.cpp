#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
    int n = -1, c = 1;
    vector<int> values(4);

    scanf("%d", &n);

    int coins[4] = {1, 5, 10, 50};

    bool ok = true;

    while(n != 0) {
        if(ok) {
            ok = false;
        } else {
            printf("\n\n");
        }
        int dp[10010];
        int cedulas[10010][4];

        memset(dp, 63, sizeof(dp));
        memset(cedulas, 0, sizeof(cedulas));
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 4; j++) if(coins[j] <= i) {
                if(dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    cedulas[i][3 - j] = cedulas[i - coins[j]][3 - j] + 1;
                }
            }
        }

        printf("Teste %d\n", c++);
        for(int i = 0; i < 4; i++) { printf("%d ", cedulas[n][i]); }
        scanf("%d", &n);
    }
    return 0;
}
