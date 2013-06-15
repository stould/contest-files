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
#include <numeric>
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

const int MAXN = 1009;
int N, M, ans, matrix[MAXN][MAXN], dp[MAXN][MAXN];

int main(void) {
    int i, j;
    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        memset(dp, 0, sizeof(dp));

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) if (matrix[i][j] == 1) {
                if (i - 1 >= 0 && j - 1 >= 0 && matrix[i-1][j-1] == 1 && matrix[i-1][j] == 1 && matrix[i][j-1] == 1) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
                if (dp[i][j] == 0) dp[i][j] = 1;
            }
        }

        ans = 0;

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}

