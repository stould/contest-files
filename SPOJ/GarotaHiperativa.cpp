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

const int MAXN = 107;
const int MOD = 100000000;

int N, M;

pair<int, int> p[MAXN];

int dp[MAXN][MAXN];
int us;

int func(int index, int last) {
    if (p[index].second == M) {
        return 1;
    }

    int& ans = dp[index][last];

    if (ans != -1) {
        return ans;
    }

    ans = 0;
    int i;

    for (i = index + 1; i < N; i++) {
        if (p[i].first > p[index].first && p[i].first <= p[index].second && p[i].second > p[index].second && (last == index || p[i].first > p[last].second)) {
            ans += func(i, index);
            if (ans >= MOD) ans -= MOD;
        }
    }

    return ans;
}

int main(void) {
    int i;

    for ( ; scanf("%d%d", &M, &N) == 2 && N + M != 0; ) {
        for (i = 0; i < N; i++) {
            scanf("%d%d", &p[i].first, &p[i].second);
        }

        sort(p, p + N);

        memset(dp, -1, sizeof(dp));

        int ans = 0;

        for (i = 0; i < N; i++) {
            if (p[i].first == 0) ans += func(i, i);
            if (ans >= MOD) ans -= MOD;
        }

        printf("%d\n", ans);
    }
    return 0;
}
