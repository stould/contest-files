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

const int MAXN = 110;

int N, K;

int a[MAXN];
int dp[MAXN][5];

int main(void) {
    N = in();
    K = in();
    
    int i, j;
    
    for (i = 0; i < N; i++) {
        a[i] = in();
    }
    
    memset(dp, 0, sizeof(dp));
    
    for (i = 0; i < N / K; i++) {
        for (j = 0; j < K; j++) {
            dp[j][a[i * K + j]] += 1;
        }
    }
    
    int ans = 0;
    
    for (i = 0; i < K; i++) {
        ans += N / K - max(dp[i][1], dp[i][2]);
   }
    
    printf("%d\n", ans);
    
    return 0;
}
