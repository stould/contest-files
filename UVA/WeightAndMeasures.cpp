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

const int MAXN = 5620;
const int INF = 101010100;

pair<int, int> p[MAXN];
int N;

int dp[MAXN][2]; //lowest weight 0 - cnt - 1

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main(void) {
    N = 1;

    int a, b, i, j, k;

    for ( ; scanf("%d%d", &a, &b) == 2; ) {
        p[N++] = make_pair(a, b);
    }

    sort(p, p + N, cmp);

    for (i = 0; i < N; i++) {
        dp[i][0] = INF;
    }

    dp[0][0] = dp[0][1] = 0;

    int ans = 0;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
	    if (dp[j - 1][0] + p[i].first <= p[i].second) {
		if (dp[j][0] < dp[j - 1][0] + p[i].first) {
		    dp[j][1] = dp[j][0];
		} else {
		    dp[j][1] = dp[j - 1][0] + p[i].first;
		}
		if (j > ans && dp[j][1] < INF) {
		    ans = j;
		}
	    } else {
		dp[j][1] = dp[j][0];
	    }
	    for (k = 0; k <= i; k++) {
		dp[k][0] = dp[k][1];
	    }
        }
    }

    printf("%d\n", ans);

    return 0;
}
