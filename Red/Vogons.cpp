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

const int MAXN = 330;

int N, M;
Int P[MAXN][MAXN];
Int dp[MAXN][MAXN][2];
int mm[MAXN][MAXN][2];
int base = 0;

Int func(int r, int c, int used) {
    if (mm[r][c][used] == base) return dp[r][c][used];

    if (c >= M) return 0;
    
    if (r >= N) {
        Int ans = 0;
        if (used) {
            ans = func(0, c + 2, 0);
        } else {
            ans = func(0, c + 1, 0);
        }
        return ans;            
    } else {
        Int& ans = dp[r][c][used];

        ans = func(r + 1, c, used);
        ans = max(ans, P[r][c] + func(r + 2, c, 1));

        mm[r][c][used] = base;
        
        return ans;
    }
}
int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    while (cin >> N >> M) {
        base += 1;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> P[i][j];
            }
        }

        Int ans = func(0, 0, 0);

        cout << ans << "\n";
    }
    return 0;
}
