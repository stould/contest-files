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

int dp[MAXN][MAXN];
bool mark[MAXN][MAXN];
int path[MAXN];

map<pair<int, int>, pair<int, int> > mp;

int func(int curr_y, int m_age, int r) {
    if (curr_y == N) {
        return 0;
    }
    if (m_age > M) {
        return INF;
    }

    if (mark[curr_y][m_age]) {
        return dp[curr_y][m_age];
    }

    mark[curr_y][m_age] = true;

    int& ans = dp[curr_y][m_age] = -INF;

    int a = (P - V[m_age]) + C[0] + func(curr_y + 1, 1, 1);
    int b = C[m_age] + func(curr_y + 1, m_age + 1, 0);

    printf("%d <-> %d %d\n", curr_y, a, b);

    if (m_age == M) {
        ans = a; mp[make_pair(curr_y, m_age)] = make_pair(curr_y + 1, 1);
    } else {
        if (a <= b) {
            ans = a; mp[make_pair(curr_y, m_age)] = make_pair(curr_y + 1, 1);
        } else {
            ans = b; mp[make_pair(curr_y, m_age)] = make_pair(curr_y + 1, m_age + 1);
        }
    }

    return ans;
}

int main(void) {
    freopen("i.in", "r", stdin);
    //freopen("o.ot", "w", stdout);
    int i, j;
    for ( ; scanf("%d%d%d%d", &N, &I, &M, &P) == 4; ) {
        for (i = 0; i < M; i++) {
            C[i] = in();
        }
        for (i = 1; i <= M; i++) {
            V[i] = in();
        }

        memset(dp, -1, sizeof(dp));
        memset(mark, false, sizeof(mark));

         for (i = 0; i < N; i++) {
            for (j = 1; j <= M; j++) {
                mp[make_pair(i, j)] = make_pair(-1, -1);
            }
        }

        int ans = func(0, I, -1);

        int index = -1, value = 1010101010;

        for (j = 1; j <= M; j++) if (mark[0][j]) {
            if (dp[0][j] <= value) {
                value = dp[0][j];
                index = j;
            }
        }

        int c = 0;

        pair<int, int> p = make_pair(0, index);

        while(mp[p] != make_pair(-1, -1) && c != 10)  {
            printf("%d %d\n", p.first, p.second);c++;
            p = mp[p];
        }

        for (i = 0; i < N; i++) {
            for (j = 1; j <= M; j++) {
                printf("%4d ", dp[i][j]);
            }
            printf("\n");
        }

        printf("%d\n", ans);
    }
    return 0;
}
