#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll N, dp[7601];
int v[5] = {1, 5, 10, 25, 50};

int main(void) {
    freopen("i.in", "r", stdin);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int j = 0; j < 5; j++) {
        for(int i = 1; i <= 7500; i++) {
            if(i - v[j] >= 0) {
                dp[i] += (ll) dp[i - v[j]];
            }
        }
    }

    while(cin >> N) {
        cout << dp[N] << endl;
    }
    return 0;
}
