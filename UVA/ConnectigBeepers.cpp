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
typedef unsigned uint;

const int INF = 101001010;

int T;

int X[15];
int Y[15];
int N;

int dp[20][1 << 20];

int func(int id, int mask) {
    if (mask == ((1 << (N + 1)) - 1)) {
        return abs(X[0] - X[id]) + abs(Y[0] - Y[id]);
    }

    int& ans = dp[id][mask];

    if (ans == -1) {
        int i;

        ans = INF;

        for (i = 0; i <= N; i++) if (i != id) {
            if (!(mask & (1 << i))) {
                int d = abs(X[id] - X[i]) + abs(Y[id] - Y[i]);

                chmin(ans, d + func(i, mask | (1 << i)));
            }
        }
    }
    return ans;
}


int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        in();
        in();

        X[0] = in();
        Y[0] = in();

        N = in();

        for (i = 1; i <= N; i++) {
            X[i] = in();
            Y[i] = in();
        }

        memset(dp, -1, sizeof(dp));
        int ans = func(0, 1 << 0);

        printf("The shortest path has length %d\n", ans);
    }
    return 0;
}
