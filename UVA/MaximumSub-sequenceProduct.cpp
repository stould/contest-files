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
const Int INF = 1010010101000010100LL;

int x[MAXN];
int N;

Int dp[MAXN];

Int func(int id) {
    if (id == N) return 1LL;

    if (dp[id] != -1LL) return dp[id];

    dp[id] = -INF;

    for (int i = id + 1; i < N; i++) {
        chmax(dp[id], (Int) x[i] * func(i + 1));
    }

    return dp[id];
}

//WA - BIGNUM Required

int main(void) {
    int i;

    for ( ; ; ) {
        int cur;
        N = 0;

        for ( ; scanf("%d", &cur) == 1 &&  cur != -999999; ) {
            x[N++] = cur;
        }

        if (N == 0) break;

        for (i = 0; i < N; i++) dp[i] = -1LL;

        if (N == 1) {
            printf("%d\n", x[0]);
        } else {
            printf("%lld\n", func(0));
        }
    }
    return 0;
}
