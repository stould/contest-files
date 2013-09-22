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

#define f first
#define s second

const int MAXN = 5050;
const int INF = 101010010;

int T, N;
pair<int, int> vp[MAXN];

int dp[MAXN];

int main(void) {
    T = in();

    int i, j;

    for ( ; T--; ) {
        N = in();

        for (i = 0; i < N; i++) {
            vp[i].s = in();
            vp[i].f = in();

            dp[i] = INF;
        }

        sort(vp, vp + N);
        N = unique(vp, vp + N) - vp;

        for (i = 0; i < N; i++) {
            vp[i].s *= -1;
            *lower_bound(dp, dp + N, vp[i].s) = vp[i].s;
        }

        printf("%d\n", lower_bound(dp, dp + N, INF) - dp);
    }
    return 0;
}
