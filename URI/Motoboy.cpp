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

const Int INF = 10101010101001000LL;

int N, P;

Int T[25];
int Q[25];

Int dp[25][1050];

Int func(int id, int w) {
    if (id == N) {
        return 0LL;
    } else {
        Int& ans = dp[id][w];

        if (ans == -1) {
            ans = func(id + 1, w);

            if (w - Q[id] >= 0) {
                chmax(ans, T[id] + func(id + 1, w - Q[id]));
            }
        }

        return ans;
    }
}

int main(void) {
    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        P = in();

        for (int i = 0; i < N; i++) {
            cin >> T[i] >> Q[i];
        }
        memset(dp, -1LL, sizeof(dp));
        printf("%lld min.\n", func(0, P));
    }
    return 0;
}
