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

const int MAXN = 580;
const int INF = INT_MAX / 3;

int N, M;
int P[MAXN];
int dp[MAXN][MAXN];
int memCost[MAXN][MAXN];
int sum[MAXN];

int cost(int l, int r) {
    if (l == r) {
        return 0LL;
    } else {
        int& ans = memCost[l][r];
        
        if (ans == -1) {
            ans = 0LL;

            for (int i = l; i < r; i++) {
                int pr = sum[r];
                if (i >= 0) {
                    pr -= sum[i];
                }
                ans += P[i] * pr;
            }
        }
        
        return ans;
    }
}

int func(int pos, int used) {
    if (used == 0) {
        return cost(pos, N - 1);
    } else if (pos == N) {
        return 0;
    } else {
        int& ans = dp[pos][used];

        if (ans == -1) {
            ans = INF;

            for (int i = pos; i < N; i++) {
                chmin(ans, cost(pos, i) + func(i + 1, used - 1));
            }
        }

        return ans;
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        for (int i = 0; i < N; i++) {
            cin >> P[i];

            if (i == 0) {
                sum[i] = P[i];
            } else {
                sum[i] = P[i] + sum[i - 1];
            }
        }

        memset(dp, -1, sizeof(dp));
        memset(memCost, -1, sizeof(memCost));

        int ans = func(0, M);
        
        cout << ans << "\n";        
    }
    return 0;
}
