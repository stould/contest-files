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

int x[MAXN];

int l[MAXN], r[MAXN];

int main(void) {
    N = in();
    L = in();
    R = in();

    QL = in();
    QR = in();

    int i;

    x[0] = x[N + 1] = 0;

    for (i = 1; i <= N; i++) {
        x[i] = in();
    }
    for (i = 1; i <= N; i++) {
        if (i == 1) {
            l[i] = x[i] * L;
        } else {
            l[i] = l[i - 1] + x[i] * L;
        }
    }

    for (i = N; i >= 1; i--) {
        if (i == N) {
            r[i] = x[i] * R;
        } else {
            r[i] = r[i + 1] + x[i] * R;
        }
    }

    Int ans = 1010101010101010LL;

 //   chmin(ans, l[N - 1] + (N - 1) * QL);
 //   chmin(ans, r[0] + (N - 1) * QR);

    for (i = 0; i <= N; i++) {
        Int curr = l[i] + r[i + 1];
        if (i > N - i) {
            curr += (2 * i - N - 1) * QL;
        }
        if (i < N - i) {
            curr += (N - 2 * i - 1) * QR;
        }
        chmin(ans, curr);
    }

    if (N == 1) {
        chmin(ans, (Int) x[1] * R);
        chmin(ans, (Int) x[1] * L);
    }

    cout << ans << "\n";

    return 0;
}
