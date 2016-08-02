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
typedef unsigned long long uInt;
typedef unsigned uint;

Int P, Q, N;
Int dp[20];

int main(void) {
    while (cin >> P >> Q >> N) {
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] * P + dp[i - 2] * Q;
        }

        cout << "x(" << N << ") = " << P << "*x(" << N - 1 << ") + " << Q << "*x(" << N - 2 << ") = " << dp[N] << endl;
    }
    return 0;
}
