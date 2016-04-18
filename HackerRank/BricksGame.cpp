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

const int MAXN = 100005;
const Int INF = 10001010100100LL;

int T, N;
Int P[MAXN];
Int dp[MAXN][2];

Int func(int pos, int turn) {
    if (pos >= N) {
        return 0;
    } else {
        Int& ans = dp[pos][turn];

        if (ans == -1) {
            if (turn == 0) {
                ans = -INF;
            } else {
                ans = +INF;
            }
            
            Int sum = 0;
            
            for (int i = 0; pos + i < N && i < 3; i++) {
                sum += P[pos + i];

                if (turn == 0) {
                    chmax(ans, sum + func(pos + i + 1, 1));
                } else {
                    chmin(ans, func(pos + i + 1, 0));
                }
            }            
        }

        return ans;
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        
        memset(dp, -1, sizeof(dp));

        cout << func(0, 0) << "\n";
    }
    return 0;
}
