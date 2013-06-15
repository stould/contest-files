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

const int MAXN = 110;
const int MOD = 1000000;
int N, K;
int dp[MAXN][MAXN]; //How many ways can we sum the number i using j numbers

int main(void) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    REP(i, MAXN) {
        REP(j, MAXN) {
            REP(k, MAXN) if(i + k < MAXN && j + 1 < MAXN) {
                dp[i + k][j + 1] += dp[i][j];
                dp[i + k][j + 1] %= MOD;
            }
        }
    }
    while(scanf("%d%d", &N, &K) == 2 && !(N+K == 0)) {
        printf("%d\n", dp[N][K]);
    }

    return 0;
}
