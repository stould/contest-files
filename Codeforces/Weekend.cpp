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

const int MAXN = 110;
const int INF = 10010001;

int T;
int N, M, K;
int F[MAXN];
int G[MAXN][MAXN];
int dp[13][1 << 13];

int func(int pos, int mask) {
    if (__builtin_popcount(mask) == K) {
        return G[F[pos]][N - 1]; 
    } else {
        int& ans = dp[pos][mask];
        
        if (ans == -1) {
            ans = INF;

            for (int i = 0; i < K; i++) {
                if (!(mask & (1 << i))) {
                    chmin(ans, G[F[pos]][F[i]] + func(i, mask | (1 << i)));
                }
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> K;

        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                if (i == j) {
                    G[i][j] = 0;
                } else {
                    G[i][j] = INF;
                }
            }
        }
        
        for (int i = 0; i < M; i++) {
            int A, B, C;

            cin >> A >> B >> C;

            A -= 1;
            B -= 1;

            G[A][B] = min(G[A][B], C);
            G[B][A] = min(G[B][A], C);
        }
        
        F[0] = 0;
        
        for (int i = 1; i <= K; i++) {
            cin >> F[i];
            F[i] -= 1;
        }
        
        K += 1;

        memset(dp, -1, sizeof(dp));
        
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        
        cout << "Case " << t << ": " << func(0, 1) << "\n";

    }
    return 0;
}
