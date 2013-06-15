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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

#define MAXN 110
#define MAXM 100100

int i, j, k, n, m, dp[MAXN][MAXM], sum[MAXM] = {0};
char maze[MAXN][MAXM];

int main(void) {
    scanf("%d%d", &n, &m);

    memset(dp, 63, sizeof(dp));

    REP(i, n) {
        scanf("%s", maze[i]);
    }

    int ans = INT_MAX, ok = 1;
    REP(i, n) {
        int last = -1;
        for(j = 0; j < m; j++) {
            if(maze[i][j] == '1') last = j;
            if(last != -1) {
                dp[i][j] = min(dp[i][j], abs(j - last));
            }
        }
        if(last == -1) {
            ok = 0;
            break;
        } else {
            for(j = 0; j < m && maze[i][j] != '1'; j++) {
                dp[i][j] = min(dp[i][j], j + (m-last));
            }
        }
        last = -1;
        for(j = m - 1; j >= 0; j--) {
            if(maze[i][j] == '1') last = j;
            if(last != -1) {
                dp[i][j] = min(dp[i][j], abs(j - last));
            }
        }
        if(last != -1) {
            for(j = m - 1; j >= 0 && maze[i][j] != '1'; j--) {
                dp[i][j] = min(dp[i][j], m - j + last);
            }
        }
    }
    REP(j, m) REP(i, n) sum[j] += dp[i][j];
    REP(i, m) ans = min(ans, sum[i]);
    printf("%d\n", !ok ? -1 : ans);
    return 0;
}

