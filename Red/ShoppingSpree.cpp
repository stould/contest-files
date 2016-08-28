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

const int MAXN = 501;

int T, N;
int P[MAXN];
int dp[MAXN][MAXN];

int func(int pos, int used) {
    if (pos >= N) {
        return 0;
    } else {
        int& ans = dp[pos][used];

        if (ans == -1) {
            ans = func(pos + 1, used);

            if (pos == 0 || (used + 1 <= (pos + 1) / 2)) {
                ans = max(ans, P[pos] + func(pos + 1, used + 1));
            }
        }

        return ans;
    }
}
int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }

        memset(dp, -1, sizeof(dp));

        cout << "Spree #" << t << ": " << func(0, 0) << "\n";
    }
    return 0;
}
