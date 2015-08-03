#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int T, N, K;
string S;

int dp[MAXN][MAXN];

int main() {
    cin >> T;
   
    for ( ; T--; ) {
        cin >> S >> K;
        N = (int) S.size();
       
        int ans = 1;
       
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - i; j++) {
                if (i == 0) {
                    dp[j][j + i] = 0;
                } else if (i == 1) {
                    dp[j][j + i] = (S[j] != S[j + 1]);
                } else {
                    dp[j][j + i] = dp[j + 1][j + i - 1];
                   
                    if (S[j] != S[j + i]) {
                        dp[j][j + i] += 1;
                    }
                }
                if (dp[j][j + i] <= K) {
                    ans = max(ans, i + 1);
                }
//                cout << j << " " << j + i << " " << dp[j][j + i] << "\n";
            }
        }
       
        cout << ans << "\n";
    }
    return 0;
}
