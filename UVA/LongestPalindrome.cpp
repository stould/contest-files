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

const int MAXN = 1025;
int T, N, dp[MAXN][MAXN];
char str[MAXN];

int rec(int l, int r) {
    if(l > r) return dp[l][r] = 0;
    if(l == r) dp[l][r] = 1;

    if(dp[l][r] != -1) return dp[l][r];

    if(str[l] == str[r]) return dp[l][r] = 2 + rec(l + 1, r - 1);
    return dp[l][r] = max(rec(l + 1, r), rec(l, r - 1));
}

int main(void) {
    //freopen("i.in", "r", stdin);
    scanf("%d", &T); getchar();
    for( ; T-- && gets(str); ) {
        N = strlen(str);

        REP(i, N) REP(j, N) dp[i][j] = -1;

        printf("%d\n", rec(0, N - 1));
    }
    return 0;
}
