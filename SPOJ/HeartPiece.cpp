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

typedef long long Int;
typedef long double ld;

int T, a[5], N;
char s[109];

Int dp[110][5][110];

Int p(int a, int b) {
    Int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a);
        }
        a = (a * 1LL * a);
        b >>= 1;
    }
    return ans;
}

Int rec(int pos, int last, int repeated) {
    if(pos >= N) return 0LL;

    Int& ans = dp[pos][last][repeated];

    if(ans != -1LL) return ans;

    ans = rec(pos + 1, last, repeated);

    int now = s[pos] - 'a';

    if(last == now) {
        if (repeated <= 9) {
            ans = (Int) (p(2, repeated) * a[now]) + rec(pos + 1, now, repeated + 1);
        } else {
            ans = (Int) (p(2, 9) * a[now]) + rec(pos + 1, now, repeated + 1);
        }
    }

    ans = max(ans, a[now] + rec(pos + 1, now, 1));

    return ans;
}

void clear (void) {
    int i, j, k;

    for (i = 0; i < 110; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 110; k++) {
                dp[i][j][k] = -1LL;
            }
        }
    }
}

int main(void) {
    //freopen("i.in", "r", stdin);
    scanf("%d", &T);

    for ( ; T--; ) {
        scanf("%d%d%d%s", &a[0], &a[1], &a[2], s);
        N = strlen(s); clear();
        printf("%lld\n", rec(0, 5, 0));
    }
    return 0;
}
