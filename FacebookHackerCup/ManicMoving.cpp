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

const int MAXN = 5050;
const Int INF = 1010101010000000000LL;

int T;
int N, M, K;
Int G[MAXN][MAXN];
int S[MAXN];
int D[MAXN];
Int dp[MAXN][6050][5];

Int func(int w, int id, int p) {
    if (p > 2) {
        return INF;
    } else if (id == K) {
        if (p == 0) {
            return 0;
        } else if (p == 1) {
            return G[w][D[id - 1]];
        } else {
            return G[w][D[id - 2]] + G[D[id - 2]][D[id - 1]];
        }
    } else {
        Int& ans = dp[w][id][p];

        if (ans == -1) {
            ans = INF;

            if (p == 2) {
                chmin(ans, G[w][D[id - 2]] + func(D[id - 2], id, 1));
            } else if (p == 1) {
                chmin(ans, G[w][D[id - 1]] + func(D[id - 1], id, 0));
                chmin(ans, G[w][S[id]] + func(S[id], id + 1, 2));
            } else {
                ans = G[w][S[id]] + func(S[id], id + 1, 1);
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> K;
        
        cout << "Case #" << t << ": ";

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                G[i][j] = INF;

                if (i == j) {
                    G[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < M; i++) {
            int a, b;
            Int c;

            cin >> a >> b >> c;

            chmin(G[a][b], c);
            chmin(G[b][a], c);
        }

        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        for (int i = 0; i < K; i++) {
            cin >> S[i] >> D[i];            
        }

        memset(dp, -1, sizeof(dp));

        Int ans = func(1, 0, 0);

        if (ans >= INF) {
            ans = -1;
        }
        
        cout << ans << endl;
    }
    return 0;
}
