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

const int MAXN = 30002;
int N, Q;
int arry[MAXN];

int tree[4 * MAXN];

void build(int node, int l, int r) {
    if (l > r) {
        return;
    } else if (l == r) {
        tree[node] = arry[l];
    } else {
        int m = (l + r) / 2;

        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node] =
    }
}

int main(void) {
    N = in();

    for (i = 0; i < N; i++) arry[i] = in();

    build(1, 0, N - 1);

    Q = in();

    for ( ; Q--; ) {
        a = in();
        b = in();


    }
    return 0;
}
