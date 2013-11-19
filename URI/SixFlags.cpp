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

const int MAXD = 660;
const int MAXP = 110;

const int INF = 1010100;

int N, T;
int D[MAXD];
int P[MAXP];

int dp[MAXD];

int func(int dur) {
    if (dur > T) return -INF;

    int& ans = dp[dur];

    if (ans == -1) {
        int i;

        ans = 0;

        for (i = 0; i < N; i++) {
            if (dur + D[i] <= T) {
                chmax(ans, P[i] + func(dur + D[i]));
            }
        }
    }
    return ans;
}

inline bool rd(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if (neg) {
        x = -x;
    }
    return true;
}

int main(void) {
    int i;
    int test = 1;

    for ( ; rd(N) && rd(T) && N + T != 0; ) {
        for (i = 0; i < N; i++) {
            rd(D[i]);
            rd(P[i]);
        }
        memset(dp, -1, sizeof(dp));
        printf("Instancia %d\n%d\n\n", test++, func(0));
    }

    return 0;
}

