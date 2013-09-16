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

const int MAXN = 22;

int T;
int N, x[MAXN];
int mid;

int dp[5][(1<<21)];

int func(int curr, int done, int mask) {
    if (done == 4) return 1;

    if (mask == (1 << N) - 1) return 0;

    if (curr == 0) {
        curr = mid;
        done += 1;
    }

    int i;
    int& ans = dp[done][mask];

    if (ans != -1) return ans;

    ans = 0;

    for (i = 0; i < N && !ans; i++) if (!((mask >> i) & 1)) {
        if (curr - x[i] >= 0) {
            ans |= func(curr - x[i], done, mask | (1 << i));
        }
    }

    return ans;
}

int main(void) {
    T = in();

    int i, j;

    for ( ; T--; ) {
        N = in();

        int sum = 0;

        for (i = 0; i < N; i++) {
            x[i] = in();
            sum += x[i];
        }

        if (sum % 4 != 0) {
            puts("no");
        } else {
            mid = sum / 4;

            for (i = 0; i < 5; i++) {
                for (j = 0; j <= (1 << (N + 1)); j++) {
                    dp[i][j] = -1;
                }
            }

            if (func(0, 0, 0)) {
                puts("yes");
            } else {
                puts("no");
            }
        }
    }
    return 0;
}
