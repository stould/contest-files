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

const int MAXN = 60;

int L, N;

int dp[MAXN][MAXN];

int x[MAXN];

int func(int l, int r) {
    if (l + 1 == r) {
        return 0;
    }

    int& ans = dp[l][r];

    if (ans == -1) {
        ans = 10101010;

        int i;

        for (i = l + 1; i < r; i++) {
            chmin(ans, x[r] - x[l] + func(l, i) + func(i, r));
        }
    }

    return ans;
}

int main(void) {
    int i;
    for ( ; scanf("%d", &L) == 1 && L != 0; ) {
        N = in();

        x[0] = 0;

        for (i = 1; i <= N; i++) {
            x[i] = in();
        }

        x[N + 1] = L;

        memset(dp, -1, sizeof(dp));

        printf("The minimum cutting is %d.\n", func(0, N + 1));
    }
    return 0;
}
