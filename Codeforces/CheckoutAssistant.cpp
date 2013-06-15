#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef long long ll;

const ll INF = 10000000000000LL;
int n;
ll mx = 0, dp[4025];

int main(void) {
    cin >> n;
    vector<pair<ll, ll> > p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second; p[i].first += 1;
    }
    for(int i = 0; i <= 4020; i++) dp[i] = INF;
    dp[0] = 0L;
    for(int i = 0; i < n; i++) {
        for(int j = 4020; j >= p[i].first; j--) {
            dp[j] = min(dp[j], dp[j - p[i].first] + p[i].second);
        }
    }
    ll ans = INF;
    for(int i = n; i <= 4020; i++) {
        if(dp[i] < ans) ans = dp[i];
    }
    cout << ans << endl;
    return 0;
}
