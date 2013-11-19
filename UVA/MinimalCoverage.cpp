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

const int MAXN = 100007;

int T, M;
int N;

pair<int, int> p[MAXN];

int main(void) {
    T = in();

    int i;
    int A, B;

    for ( ; T--; ) {
        M = in();

        N = 0;

        for ( ; scanf("%d%d", &A, &B) == 2 && (A + B != 0); ) {
            if (B < 0) continue;
            p[N++] = make_pair(A, B);
        }

        sort(p, p + N);

        for ()

    }

    return 0;
}
