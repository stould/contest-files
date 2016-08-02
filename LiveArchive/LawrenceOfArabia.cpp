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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1010;
const Int INF = 100100101001001000LL;

int N, M;
int P[MAXN];
Int dp[MAXN][MAXN];
Int memCost[MAXN][MAXN];
Int sum[MAXN];

Int cost(int l, int r) {
    if (l == r) {
        return 0LL;
    } else {
        Int& ans = memCost[l][r];
        
        if (ans == -1) {
            ans = 0LL;

            for (int i = l; i < r; i++) {
                Int pr = sum[r];
                
                if (i >= 0) {
                    pr -= sum[i];
                }
                ans += P[i] * pr;
            }
        }
        
        return ans;
    }
}

Int func(int pos, int used) {
    if (used == 0) {
        return cost(pos, N);
    } else if (pos == N + 1) {
        return 0;
    } else {
        Int& ans = dp[pos][used];

        if (ans == -1) {
            ans = INF;

            for (int i = pos; i < N; i++) {
                chmin(ans, cost(pos, i) + func(i + 1, used - 1));
            }
        }

        return ans;
    }
}

void cost(int k, int l, int r, int optL, int optR) {
    if (l > r) return;
    
    int m = (l + r) / 2;
    
    Int best = INF;
    int id = optL;
    
    for (int i = optL; i <= min(m, optR); i++) {
        Int now = dp[i][k - 1] + cost(i + 1, m);
        
        if (now < best) {
            best = now;
            id = i;
        }
    }
    
    dp[m][k] = best;
    
    cost(k, l, m - 1, optL, id);
    cost(k, m + 1, r, id, optR);
}

int main(void) {
    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0) {
            break;
        }
        for (int i = 1; i <= N; i++) {
            cin >> P[i];

            sum[i] = P[i] + sum[i - 1];            
        }

        memset(memCost, -1, sizeof memCost);

        for (int i = 1; i <= N; i++) {        
            dp[i][0] = cost(1, i);
        }
        
        for (int i = 1; i <= M; i++) {
            cost(i, 1, N, 1, N);
        }
        
        Int ans = INF;

        for (int i = 0; i <= M; i++) {
            ans = min(ans, dp[N][i]);
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
