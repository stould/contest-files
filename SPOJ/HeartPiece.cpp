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

typedef long long ll;
typedef long double ld;

int T, a[5], dp[110][5][15], N;
char s[109];

int rec(int pos, int last, int repeated) {
    if(pos >= N) return 0;

    if(dp[pos][last][repeated] != -1) return dp[pos][last][repeated];

    dp[pos][last][repeated] = 0;

    int now = s[pos] - 'a';

    if(repeated <= 9 && last == now) {
        dp[pos][last][repeated] = a[now] * (2, repeated) + rec(pos + 1, now, repeated + 1);
    }
    dp[pos][last][repeated] = max(dp[pos][last][repeated], a[now] + rec(pos + 1, now, 1));
    printf("%d %d %d\n", pos, last, dp[pos][last][repeated]);
    return dp[pos][last][repeated] = max(dp[pos][last][repeated], rec(pos + 1, last, repeated));
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &T);

    for ( ; T--; ) {
        scanf("%d%d%d%s", &a[0], &a[1], &a[2], s);
        N = strlen(s); memset(dp, -1, sizeof(dp));
        printf("%d\n", rec(0, 3, 1)); //last = 3, represente que não houve letra antecessora ao caso base
    }
    return 0;
}
