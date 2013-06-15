#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

const int INF = 1000000000;
int T, P, N, dp[10011];

int main(void) {
    cin >> T;
    while(T--) {
        cin >> P >> N;
        vector<int> coins;
        for(int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            coins.push_back(tmp);
        }
        for(int i = 0; i <= 10010; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;
        for(int j = 0; j < (int) coins.size(); j++) {
            for(int i = 10010; i >= 0; i--) {
                if(coins[j] + i <= 10010) {
                    dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
                }
            }
        }
        int ans, amount;
        for(int i = P; i <= 10000; i++) {
            if(dp[i] != INF) {
                ans = i;
                amount = dp[i];
                break;
            }
        }
        cout << ans << " " << amount << endl;
    }
    return 0;
}
