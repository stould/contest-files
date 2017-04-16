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

const int MAXN = 120;
const Int INF = 10010100101000010LL;

int N, K;
Int R[MAXN];
Int dp[MAXN][10][MAXN];

Int func(int pos, int used, int len) {
    if (len == N) {
        return used == K ? 0 : INF;
    } else {
        Int& ans = dp[pos][used][len];

        if (ans == -1LL) {
            ans = INF;
            
            Int sum = 0;

            for (int i = 0; i < N - len; i++) {
                int next = (pos + i) % N;
                sum += i * (Int) R[next];

                chmin(ans, sum + func((next + 1) % N, used + 1, len + (i + 1)));
            }
        }

        return ans;
    }
}

int main(void) {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    Int ans = INF;

    for (int i = 0; i < N; i++) {
        memset(dp, -1, sizeof(dp));
        chmin(ans, func(i, 0, 0));
    }
    
    cout << ans << "\n";
    
    return 0;
}
