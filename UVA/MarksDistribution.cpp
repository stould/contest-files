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

const int MAXN = 90;
int K, N, T, P;
int dp[MAXN][MAXN][MAXN];

int main(void) {
    scanf("%d", &K);

    REP(i, 80) dp[0][0][i] = 1;

    REP(i, 80) REP(j, 70) REP(k, 70) {
        REP(l, j - (i * k) + k) if(i > 0) {
            dp[i][j][k] += dp[i-1][j - l][k];
        }
    }
    for( ; K--; ) {
        scanf("%d%d%d", &N, &T, &P);
        //memset(dp, -1, sizeof(dp));
        printf("%d\n", dp[N][T][P]);
    }
    return 0;
}

