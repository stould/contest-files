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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int INF = INT_MAX / 3;
const int MAXN = 2020;

int I, N, M, P;
int C[MAXN], V[MAXN];

int dp[MAXN][MAXN][2];
int path[MAXN];
int mark[MAXN];

int func(int curr_y, int m_age) {
    if (curr_y == N) {
        return 0;
    }
    if (m_age > M) {
        return INF;
    }

    if (dp[curr_y][m_age][0] != -1) {
        return dp[curr_y][m_age][0];
    }

    int& ans = dp[curr_y][m_age][0] = 0;

    int a = P - V[m_age - 1] + C[0] + func(curr_y + 1, 1);
    int b = C[m_age] + func(curr_y + 1, m_age + 1);

    if (m_age == M || a <= b) {
        ans = a; dp[curr_y][m_age][1] = 1;
    } else {
        ans = b; dp[curr_y][m_age][1] = 0;
    }

    return ans;
}

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    int i;
    for ( ; scanf("%d%d%d%d", &N, &I, &M, &P) == 4; ) {
        for (i = 0; i < M; i++) {
            C[i] = in();
        }
        for (i = 0; i < M; i++) {
            V[i] = in();
        }

        memset(dp, -1, sizeof(dp));
        memset(mark, 55, sizeof(mark));
        int ans = func(0, I);

        for (i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%4d ", dp[i][j][1]);
            }
            printf("\n");
        }
        for (i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%4d ", dp[i][j][0]);
            }
            printf("\n");
        }

        printf("\n");

        printf("%d\n", ans);
    }
    return 0;
}
