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

const int MAXN = 100007;
const int INF = INT_MAX / 3;

int N, Q, T, A, B;

int x[MAXN];
int lazy[4 * MAXN];

struct data {
    int d[3];

    data(){
        d[0] = 1;
        d[1] = d[2] = 0;
    }

    data(int a, int b, int c) {
        d[0] = a;
        d[1] = b;
        d[2] = c;
    }
};

data tree[4 * MAXN];

data combine(data& a, data& b) {
    data ans = data(a.d[0] + b.d[0], a.d[1] + b.d[1], a.d[2] + b.d[2]);
    return ans;
}

void fix(int node, int f) {
    if (f % 3 == 0) return;
    if (f % 3 == 1) {
        swap(tree[node].d[0], tree[node].d[1]);
        swap(tree[node].d[0], tree[node].d[2]);
        return;
    }
    swap(tree[node].d[0], tree[node].d[2]);
    swap(tree[node].d[0], tree[node].d[1]);
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
    if (l == r) {
        lazy[node] = 0;
        tree[node] = data(1, 0, 0);
    } else {
        int m = (l + r) / 2;

        lazy[node] = 0;

        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int l, int r, int bound_l, int bound_r) {
    func(node, l, r);
    if (bound_l > bound_r) {
        return;
    } else if (bound_l <= l && bound_r >= r) {
        lazy[node] += 1;
        func(node, l, r);
    } else {
        int m = (l + r) / 2;

        update(2 * node, l, m, bound_l, min(m, bound_r));
        update(2 * node + 1, m + 1, r, max(m + 1, bound_l), bound_r);

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int node, int l, int r, int bound_l, int bound_r) {
    func(node, l, r);
    if (bound_l > bound_r) {
        return INF;
    } else if (l >= bound_l && r <= bound_r) {
        return tree[node].d[0];
    } else {
        int m = (l + r) / 2;

        if (bound_r <= m) {
            return query(2*node, l, m, bound_l, bound_r);
        }

        if (bound_l > m) {
            return query(2*node+1, m+1, r, bound_l, bound_r);
        }

        int a = query(2 * node, l, m, bound_l, min(bound_r, m));
        int b = query(2 * node + 1, m + 1, r, max(bound_l, m + 1), bound_r);

        return a + b;
    }
}

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

int main(void) {
    readI(N);
    readI(Q);

    REP(i, N) x[i] = 0;

    build(1, 0, N - 1);

    REP(i, Q) {
        readI(T);
        readI(A);
        readI(B);

        if(T == 0) {
            update(1, 0, N - 1, A, B);
        } else {
            int ans = query(1, 0, N - 1, A, B);
            printf("%d\n", ans);
        }
    }
    return 0;
}
