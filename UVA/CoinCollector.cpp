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

int T;
int N;

int x[1010];

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        N = in();
        for (i = 0; i < N; i++) {
            x[i] = in();
        }

        Int sum = (Int) x[0], ans = 2;

        for (i = 1; i < N - 1; i++) {
            if (sum + x[i] < x[i + 1]) {
                sum += (Int) x[i];
                ans += 1;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
