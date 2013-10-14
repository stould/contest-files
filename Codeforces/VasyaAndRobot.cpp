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

const int MAXN = 100005;
const int INF = INT_MAX / 3;

int N, L, R, QL, QR;

int dp[MAXN / 2][MAXN / 2][5];

int x[MAXN];

int func(int a, int b, int last) {
    if (a > b) {
        return 0;
    }

    int& ans = dp[a][b][last];

    if (ans != -1) return ans;

    int get_left = x[a] * L + func(a + 1, b, 1) + (last == 1 ? QL : 0);
    int get_righ = x[b] * R + func(a, b - 1, 2) + (last == 2 ? QR : 0);

    ans = min(get_left, get_righ);

    return ans;
}

int main(void) {
    freopen("i.in", "r", stdin);
    N = in();
    L = in();
    R = in();

    QL = in();
    QR = in();

    int i;

    for (i = 0; i < N; i++) {
        x[i] = in();
    }

    memset(dp, -1, sizeof(dp));

    int ans = func(0, N - 1, 0);

    printf("%d\n", ans);

    return 0;
}
