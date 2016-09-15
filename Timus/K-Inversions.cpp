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

const int MAXN = 20005;

int N, K;

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    update(1, P[0], 1);
    
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[j] = query(j - 1, P[i] + 1, MAXN);
        }
    }
    return 0;
}
