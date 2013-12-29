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

const int MAXN = 17;

int T, N;
int X[MAXN], Y[MAXN], Z[MAXN];

//0 = X, Y; 1 = X, Z; 2 = Y, Z
int dp[MAXN][MAXN][5];

int rec(int index, int last, int kind) {
    if (index == N) return 0;

    int& ret = dp[index][last][kind];

    if (ret != -1) return ret;

    ret = rec(index + 1, last, kind);

    if (kind == -1) {
        chmmax(ret, Z[index] + rec(index + 1, index, 0));
        chmmax(ret, Y[index] + rec(index + 1, index, 1));
        chmmax(ret, X[index] + rec(index + 1, index, 2));
    } else {
        if (kind == 0) {
            if ((X[index] <= X[last] && Y[index] <= Y[last]) || (X[index] <= X[last] && Y[index] <= Y[last])) {
                chmmax(ret, Z[index] + rec(index + 1, index, 0));
            }
            if (X[index] <= X[last] && Y[index] <= Y[last]) {
                chmmax(ret, Z[index] + rec(index + 1, index, 0));
            }
        } else if (kind == 1) {

        } else {

        }
    }

    return ret;
}

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        N = in();

        for (i = 0; i < N; i++) {
            X[i] = in();
            Y[i] = in();
            Z[i] = in();
        }

        printf("%d\n", rec(0, -1, -1));
    }
    return 0;
}
