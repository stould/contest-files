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

const int MAXN = 100007;

inline void readI(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}

struct data {
    int h, e, r;

    data() {
        h = 1;
        e = r = 0;
    }
};

int N, M;
data tree[4 * MAXN];
int  lazy[4 * MAXN];

data combine(data a, data b) {
    data ans;
    ans.h = a.h + b.h;
    ans.e = a.e + b.e;
    ans.r = a.r + b.r;
    return ans;
}

data dumb_data(void) {
    data ans;
    ans.h = ans.e = ans.r = 0;
    return ans;
}

//Homem - 0, Elefante - 1, Rato - 2

void fix(int node, int f) {
    if (f % 3 == 0) return;
    if (f % 3 == 1) {
        swap(tree[node].h, tree[node].e);
        swap(tree[node].h, tree[node].r);
        return;
    }
    swap(tree[node].h, tree[node].r);
    swap(tree[node].h, tree[node].e);
}

void func(int node, int l, int r) {
    if (lazy[node]) {
        fix(node, lazy[node]);
        if (l != r) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void build(int node, int l, int r) {
    if (l > r) {
        return;
    } else if (l == r) {
        lazy[node] = 0;
        tree[node] = data();
    } else {
        lazy[node] = 0;
        int m = (l + r) / 2;
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int l, int r, int bound_l, int bound_r) {
    func(node, l, r);
    if (bound_l > bound_r) {
        return;
    } else if (bound_l == l && bound_r == r) {
        lazy[node] += 1;
        func(node, l, r);
    } else {
        int m = (l + r) / 2;
        update(2 * node, l, m, bound_l, min(m, bound_r));
        update(2 * node + 1, m + 1, r, max(m + 1, bound_l), bound_r);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

data query(int node, int l, int r, int bound_l, int bound_r) {
    func(node, l, r);
    if (bound_l > bound_r) {
        return dumb_data();
    }
    if (l >= bound_l && r <= bound_r) {
        return tree[node];
    }
    int m = (l + r) / 2;
    if (bound_r <= m) {
        return query(2*node, l, m, bound_l, bound_r);
    }
    if (bound_l > m) {
        return query(2*node+1, m+1, r, bound_l, bound_r);
    }
    return combine(query(2*node, l, m, bound_l, min(m, bound_r)), query(2*node+1, m + 1, r, max(m + 1, bound_l), bound_r));
}

int main(void) {
    char kind;
    int a, b;

    for ( ; scanf("%d%d", &N, &M) == 2; ) {
        build(1, 0, N - 1);

        for ( ; M--; ) {
            scanf(" %c%", &kind);

            readI(a);
            readI(b);

            if (kind == 'M') {
                update(1, 0, N - 1, a - 1, b - 1);
            } else {
                data ans = query(1, 0, N - 1, a - 1, b - 1);

                printf("%d %d %d\n", ans.h, ans.e, ans.r);
            }
        }

        printf("\n");
    }

    return 0;
}

