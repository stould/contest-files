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
const int INF = 10001010LL;
int T, N, H, W;

int matrix[MAXN][MAXN], dp[MAXN][MAXN];

int func(int i, int j) {
    if (i == H) return 0;
    if (j < 0 || j >= W) return -INF;

    int& ret = dp[i][j];

    if (ret != -1) return ret;

    chmax(ret, matrix[i][j] + func(i + 1, j));
    chmax(ret, matrix[i][j] + func(i + 1, j + 1));
    chmax(ret, matrix[i][j] + func(i + 1, j - 1));

    return ret;
}

int main(void) {
    T = in();

    int i, j;


    for ( ; T--; ) {
        H = in(), W = in();

        for (i = 0; i < H; i++) {
            for (j = 0; j < W; j++) {
                matrix[i][j] = in();
                dp[i][j] = -1;
            }
        }

        int ans = 0;

        for (j = 0; j < W; j++) ans = max(ans, func(0, j));

        printf("%d\n", ans);
    }
    return 0;
}
