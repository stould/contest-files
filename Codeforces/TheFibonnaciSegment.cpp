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

const int MAXN = 100005;

int N;

int X[MAXN];
int ok[MAXN];

int main(void) {
    N = in();

    int i;

    for (i = 0; i < N; i++) {
        X[i] = in();
        ok[i] = i <= 1 ? 1 : 0;

        if (i > 1 && X[i] == X[i - 1] + X[i - 2]) {
            ok[i] = 1;
        }
    }

    int ans = 0;

    for (i = 2; i < N; i++) {
        int j = i;
        int cnt = 2;

        for ( ; j < N && ok[j] == 1; ) {
            j += 1;
            cnt += 1;
        }
        chmax(ans, cnt);
        i = j;
    }

    if (N <= 2) chmax(ans, N);

    printf("%d\n", ans);

    return 0;
}

