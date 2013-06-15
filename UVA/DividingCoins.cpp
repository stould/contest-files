#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int n, m, sum, ans, dp[55000], coins[200];

int main(void) {
    cin >> n;
    for(int x = 0; x < n; x++) {
        cin >> m;
        sum = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; i++) {
            cin >> coins[i];
            sum += coins[i];
        }
        dp[0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = sum; j >= coins[i]; j--) {
                dp[j] |= dp[j - coins[i]];
            }
        }
        ans = 300000000;
        for(int i = sum; i >= 0; i--) {
            if(dp[i]) {
                ans = min(ans, abs(i - abs(sum - i)));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
