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

unsigned long long int F[70];

int main(void) {
    F[0] = 0;
    F[1] = 1;

    int i;

    for (i = 2; i <= 60; i++) F[i] = F[i - 1] + F[i - 2];

    T = in();

    for ( ; T--; ) {
        int x = in();

        printf("Fib(%d) = %llu\n", x, F[x]);
    }

    return 0;
}
