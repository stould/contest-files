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

double T;
double N[110];

int main(void) {
    cin >> T;

    N[0] = T;

    int i;

    printf("N[%d] = %.4lf\n", 0, N[0]);

    for (i = 1; i < 100; i++) {
        N[i] = N[i - 1] / 2.0;

        printf("N[%d] = %.4lf\n", i, N[i]);
    }

    return 0;
}
