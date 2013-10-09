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

const int MAXN = 100003;

const int INF = 1010110;

struct data {
    int a, b;

    data() {

    }

    data(int _a, int _b) {
        a = _a;
        b = _b;
    }
};

int N, Q;
int arry[MAXN];
data tree[4 * MAXN];

data combine(data a, data b) {
    data ans;

    int as[4] = {a.a, a.b, b.a, b.b}; sort(as, as + 4);

    ans.a = as[3];
    ans.b = as[2];

    return ans;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = data(arry[l], 0);
    } else {
        int m = (l + r) / 2;

        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

int ans;

data query(int node, int l, int r, int bound_l, int bound_r) {
    if (bound_l > bound_r) {
        return data(-INF, -INF);
    } else if (l >= bound_l && r <= bound_r) {
        return tree[node];
    } else {
        int m = (l + r) / 2;

        data a = query(2 * node, l, m, bound_l, min(m, bound_r));
        data b = query(2 * node + 1, m + 1, r, max(m + 1, bound_l), bound_r);

        return combine(a, b);
    }
}

void update(int node, int l, int r, int pos, int v) {
    if (l > r) {
        return;
    } else if (l == r) {
        tree[node].a = v;
    } else {
        int m = (l + r) / 2;

        if (pos <= m) {
            update(2 * node, l, m, pos, v);
        } else {
            update(2 * node + 1, m + 1, r, pos, v);
        }

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

int main(void) {
    int a, b, i;
    char kind;

    for ( ; scanf("%d", &N) == 1; ) {
        for (i = 0; i < N; i++) {
            arry[i] = in();
        }

        build(1, 0, N - 1);

        Q = in();

        for ( ; Q--; ) {
            scanf(" %c%d%d", &kind, &a, &b);

            if (kind == 'Q') {
                data ans = query(1, 0, N - 1, a - 1, b - 1);
                printf("%d\n", ans.a + ans.b);
            } else {
                update(1, 0, N - 1, a - 1, b);
            }
        }
    }
    return 0;
}
