
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}

template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 10010;
const int MOD = 1000000007;
int T, N, K, v[MAXN], test = 1;

ll dp[MAXN][MAXN];

ll rec(int a, int b) {
    if(a < b || b < 0) return 0LL;
    if(a <= 1) return 1LL;
    if(a == b) return 1LL;

    if(dp[a][b] != -1LL) return dp[a][b];

    return dp[a][b] = (ll) (rec(a-1, b-1) + (ll) rec(a-1, b)) % MOD;
}

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o2.out", "w", stdout);

    memset(dp, -1LL, sizeof(dp));

    scanf("%d", &T);
    for( ; T-- ; ) {
        scanf("%d%d", &N, &K);
        REP(i, N) scanf("%d", &v[i]);

        sort(v, v + N);
        ll ans = 0LL;
        for(int i = K - 1; i < N; i++) {
            ans = (ll) (ans + (rec(i, K-1)*v[i])) % MOD;
        }
        printf("Case #%d: %lld\n", test++, ans);
    }
    return 0;
}
