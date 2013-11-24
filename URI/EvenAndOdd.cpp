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
int P[MAXN], I[MAXN];

int main(void) {
    N = in();

    int i;
    int pi = 0, ii = 0;

    for (i = 0; i < N; i++) {
        int x = in();
        if (x % 2 == 0) {
            P[pi++] = x;
        } else {
            I[ii++] = x;
        }
    }

    sort(P, P + pi);
    sort(I, I + ii);
    reverse(I, I + ii);

    for (i = 0; i < pi; i++) {
        printf("%d\n", P[i]);
    }
    for (i = 0; i < ii; i++) {
        printf("%d\n", I[i]);
    }

    return 0;
}
