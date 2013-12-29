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

const int MAXN = 13;

int R, C, ans;
char state[MAXN][MAXN];
int eaten[MAXN][MAXN];

int main(void) {
    R = in(), C = in();

    int i, j, k;

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            scanf(" %c", &state[i][j]);
        }
    }

    memset(eaten, 0, sizeof(eaten));

    ans = 0;

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            int cnt = 0, straw = 0;
            for (k = 0; k < R; k++) {
                if (state[k][j] == 'S') {
                    straw = 1; break;
                }
                if (!eaten[k][j]) {
                    cnt += 1;
                }
            }
            if (!straw) {
                ans += cnt;
                for (k = 0; k < R; k++) eaten[k][j] = 1;
            }
        }
    }

    for (j = 0; j < C; j++) {
        for (i = 0; i < R; i++) {
            int cnt = 0, straw = 0;
            for (k = 0; k < C; k++) {
                if (state[i][k] == 'S') {
                    straw = 1; break;
                }
                if (!eaten[i][k]) {
                    cnt += 1;
                }
            }
            if (!straw) {
                ans += cnt;
                for (k = 0; k < C; k++) eaten[i][k] = 1;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
