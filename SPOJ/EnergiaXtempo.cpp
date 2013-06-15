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

const int INF = 1000101010;

int F, P, E, A, dp[5005][22], cost[5005][22][3];

int main(void) {
    while(4 == scanf("%d%d%d%d", &F, &P, &E, &A) && !(F+P+E+A == 0)) {
        memset(dp, 63, sizeof(dp));
        REP(i, P) REP(j, F) REP(k, 2) scanf("%d", &cost[i][j][k]);

        dp[0][0] = 0;
        FOR(i, 1, 21) dp[0][i] = E*A;

        FOR(i, 1, P+1) {
            REP(j, F) {
                REP(k, F) {
                    int next = cost[i-1][k][0] * cost[i-1][k][1];
                    if(j != k) next += E*A;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + next);
                }
            }
        }
        int ans = INF;
        REP(i, F) ans = min(ans, dp[P][i]);
        printf("%d\n", ans);
    }
    return 0;
}

