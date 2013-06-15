#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 10000000;

int n, v[3], dp[4010];

int main(void) {
    cin >> n >> v[0] >> v[1] >> v[2];
    sort(v, v + 3);

    for(int i = 0; i <= n; i++) dp[i] = -INF;
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) if(v[j] <= i) {
            if(dp[i - v[j]] + 1 > dp[i]) {
                dp[i] = dp[i - v[j]] + 1;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
