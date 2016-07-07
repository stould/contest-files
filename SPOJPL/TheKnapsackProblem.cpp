#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 2020;

int S, N;
pair<int, int> P[MAXN];
int dp[2][MAXN];

int main(void) {
    cin >> S >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }

    for (int i = 0; i < N; i++) {
        int pr = i % 2;
        
        for (int j = 0; j <= S; j++) {
            dp[pr][j] = dp[pr ^ 1][j];
            
            if (j - P[i].first >= 0) {
                dp[pr][j] = max(dp[pr][j], dp[pr ^ 1][j - P[i].first] + P[i].second);
            }
        }
    }
    int ans = 0;

    for (int i = 0; i <= S; i++) {
        ans = max(ans, max(dp[0][i], dp[1][i]));
    }

    cout << ans << endl;
    return 0;
}
