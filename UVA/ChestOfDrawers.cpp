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

const int MAXN = 70;

int N, S;

Int dp[MAXN][MAXN][2];

Int func(int index, int secured, int last) {
    if (index == N) {
        if (secured == S) {
            return 1LL;
        } else {
            return 0LL;
        }
    }

    Int& ans = dp[index][secured][last];

    if (ans != -1LL) return ans;

    ans = 0LL;

    ans += func(index + 1, secured, 0);

    if (last == 1) {
        if (secured + 1 <= S) ans += func(index + 1, secured + 1, 1);
    } else {
        ans += func(index + 1, secured, 1);
    }

    return ans;
}

int main(void) {
    for ( ; ; ) {
        N = in(), S = in();

        if (N < 0 && S < 0) break;

        memset(dp, -1LL, sizeof(dp));

        printf("%lld\n", func(0, 0, 1));
    }
    return 0;
}
