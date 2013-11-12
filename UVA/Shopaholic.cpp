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

const int MAXN = 20007;

int T, N;

int x[MAXN];

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        N = in();

        for (i = 0; i < N; i++) {
            x[i] = in();
        }

        sort(x, x + N);
        reverse(x, x + N);

        int ans = 0;

        for (i = 0; i + 2 < N; i += 3) {
            ans += x[i + 2];
        }

        printf("%d\n", ans);
    }
    return 0;
}
