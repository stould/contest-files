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

const Int MOD = 100000007LL;
const int MAXN = 500005;

int T, N, M;
Int dp[MAXN][300];

Int func_naive(int pos, int used) {
    if (pos >= M) {
        return used * 2 > N ? 1LL : 0LL;
    } else {
        Int& ans = dp[pos][used];

        if (ans == -1) {
            ans = 0;

            for (int i = 1; i <= N; i++) {
                if (used * 2 <= N && i < 2 * used) {
                    continue;
                }
                ans += func_naive(pos + 1, i);
                ans = ((ans % MOD) + MOD) % MOD;
            }
        }
        
        ans = ((ans % MOD) + MOD) % MOD;
        return ans;
    }
}

Int func(int pos, int last) {
    if (pos >= M) {
        return last == 1 ? 1LL : 0LL;
    } else {
        Int& ans = dp[pos][last];

        if (ans == -1) {
            ans = 0;
            
            if (last == 1) {
                ans += ((N + 1) / 2) * func(pos + 1, 1);
                ans = ((ans % MOD) + MOD) % MOD;
                ans += ((N + 0) / 2) * func(pos + 1, 0);
                ans = ((ans % MOD) + MOD) % MOD;
            } else {
                ans += ((N + 1) / 2) * func(pos + 1, 1);
                ans = ((ans % MOD) + MOD) % MOD;
            }
        }
        
        ans = ((ans % MOD) + MOD) % MOD;
        
        return ans;
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        memset(dp, -1, sizeof(dp));

        cout << func_naive(0, N) << "\n";
    }
    return 0;
}
