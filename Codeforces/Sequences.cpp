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

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 200020;

int T, N;
int dp[MAXN], pos[MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        
        int P, ans = 1;

        for (int i = 0; i < MAXN; i++) {
            pos[i] = -1;
        }

        for (int i = 0; i < N; i++) {
            cin >> P;
            
            dp[i] = 1;
            
            if (pos[P - 1] != -1) {
                dp[i] = max(dp[i], dp[pos[P - 1]] + 1);
            }
            
            pos[P] = i;
            
            chmax(ans, dp[i]);
        }
        cout << ans << "\n";
    }

    return 0;
}
