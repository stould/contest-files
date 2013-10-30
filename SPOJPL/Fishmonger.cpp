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

const int MAXN = 1010;
const Int INF = 0x3f3f3f3f;

int N, T;

Int t[MAXN][MAXN];
Int c[MAXN][MAXN];

pair<Int, Int> dp[MAXN][MAXN];

pair<Int, Int> func(int id, int len) {
    if (id == N - 1) {
        return make_pair(0LL, 0LL);
    }
    if (len > T) {
        return make_pair(INF, INF);
    }

    pair<Int, Int>& ans = dp[id][len];

    if (dp[id][len].first != -1) {
        return dp[id][len];
    }

    ans = make_pair(INF, INF);

    int i;

    for (i = 0; i < N; i++) if (i != id && len + t[id][i] <= T) {
        pair<Int, Int> aux = func(i, len + t[id][i]);

        aux.first += c[id][i];
        aux.second += t[id][i];

        if (aux.first < ans.first) {
            ans = aux;
        }
    }

    return dp[id][len] = ans;
}

int main(void) {
    int i, j;
    for ( ; scanf("%d%d", &N, &T) == 2 && N + T != 0; ) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%lld", &t[i][j]);
            }
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%lld", &c[i][j]);
            }
        }

        for (i = 0; i <= N; i++) {
            for (j = 0; j <= T; j++) {
                dp[i][j].first = -1;
            }
        }

        pair<Int, Int> ans = func(0, 0);

        printf("%lld %lld\n", ans.first, ans.second);
    }
    return 0;
}
