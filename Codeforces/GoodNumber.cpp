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

int N, K;

int func(int x) {
    int di[10]; memset(di, 0, sizeof(di));

    for ( ; x > 0; x /= 10) {
        di[x % 10] = 1;
    }

    int i;

    for (i = 0; i <= K; i++) if (!di[i]) return false;

    return true;
}

int main(void) {
    N = in();
    K = in();

    int i;
    int ans = 0;

    for (i = 0; i < N; i++) {
        int x = in();
        ans += func(x);
    }

    printf("%d\n", ans);
    return 0;
}
