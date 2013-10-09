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

const int MAXB = 125;
const int MAXS = 252;

const int INF = INT_MAX / 3;

int S, B;

int bs[MAXB], sp[MAXS];

int dp[MAXB][MAXS];
bool mark[MAXB][MAXS];

int func(int b_id, int s_id, int start, bool ran) {
    if (b_id == B) {
        return 0;
    }
    if ((s_id + 1) % S == start || (s_id == start && ran)) {
        return INF;
    }

    if (mark[b_id][s_id]) {
        return dp[b_id][s_id];
    } else {
        int& ans = dp[b_id][s_id] = INF;

        mark[b_id][s_id] = true;

        chmin(ans, func(b_id, (s_id + 1) % S, start, true));

        int f = bs[b_id] * (sp[s_id] + sp[(s_id + 1) % S]);

        chmin(ans, f + func(b_id + 1, (s_id + 2) % S, start, true));

        return ans;
    }
}

int main(void) {
    int i, j, k;
    for ( ; scanf("%d%d", &S, &B) == 2 && S + B != 0; ) {
        for (i = 0; i < S; i++) sp[i] = in();
        for (i = 0; i < B; i++) bs[i] = in();

        int ans = INF;

        for (i = 0; i < S; i++) {
            memset(mark, false, sizeof(mark));
            chmin(ans, func(0, i, i, false));
        }

        printf("%d\n", -ans);
    }
    return 0;
}
