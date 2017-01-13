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

const int MAXN = 1010;
const Int MOD = 1000000009LL;

int N, M, K;
Int P[MAXN], Q[MAXN];
Int dp[MAXN][MAXN][11];

Int func(int i, int j, int k) {
    if (k > K) {
        return 0;        
    } else if (i == N or j == M) {
        if (k == K) {
            return 1;
        } else {
            return 0;
        }
    } else {
        Int& ans = dp[i][j][k];

        if (ans == -1) {
            ans = 0;

            ans += func(i, j + 1, k) % MOD;
            ans += func(i + 1, j, k) % MOD;
            
            if (P[i] > Q[j]) {
                ans += func(i + 1, j + 1, k + 1) % MOD;
            }
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
        
        return ans % MOD;
    }
}

int main(void) {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    sort(P, P + N);
    
    for (int i = 0; i < M; i++) {
        cin >> Q[i];
    }
    sort(Q, Q + M);
    
    memset(dp, -1, sizeof(dp));

    cout << func(0, 0, 0) << endl;
    return 0;
}
