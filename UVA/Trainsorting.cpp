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

const int MAXN = 2010;

int T;
int N;

int x[MAXN];

int A[MAXN];
int B[MAXN];

int func(void) {
    int i, j;

    int ans = 0;

    for (i = N - 1; i >= 0; i--) {
        for (j = i + 1; j < N; j++) {
            if (x[i] < x[j]) {
                chmax(A[i], A[j] + 1);
            } else {
                chmax(B[i], B[j] + 1);
            }
        }
    }

    for (i = 0; i < N; i++) {
        chmax(ans, A[i] + B[i] - 1);
    }

    return ans;
}

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        N = in();

        for (i = 0; i < N; i++) {
            x[i] = in();

            A[i] = B[i] = 1;
        }
        printf("%d\n", func());
    }
    return 0;
}
