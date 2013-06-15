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
const int INF = 10000010;

int a[MAXN];

template<typename T>
struct SegmentTree {
    int N;
    T tree[3*MAXN];

    SegmentTree(int _N) {
        N = _N;
        for(int i = 0; i < 3*MAXN; i++) tree[i] = 0;
    }

    void build(T a[], int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, v*2, tl, mid);
            build(a, v*2+1, mid+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    void build(T a[]) {
        build(a, 1, 0, N);
    }

    T sum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if(l == tl && r == tr) {
            return tree[v];
        }
        int mid = (tl + tr) / 2;
        return sum(v*2, tl, mid, l, min(r,mid)) + sum(v*2+1, mid+1, tr, max(l,mid+1), r);
    }

    T sum(int l, int r) {
        return sum(1, 0, N, l, r);
    }

    void update_add_range_helper(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return;
        }
        if(l == tl && tr == r) {
            tree[v] = sqrt(tree[v]);
        } else {
            int mid = (tl + tr) >> 1;
            update_add_range_helper(v*2, tl, mid, l, min(r,mid));
            update_add_range_helper(v*2+1, mid+1, tr, max(l,mid+1), r);
            tree[v] = tree[v*2] + tree[v*2 + 1];
        }
    }

    void update_range(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return;
        }
        if(l == tl && tr == r) {
            tree[v] = sqrt(tree[v]);
        } else {
            int mid = (tl + tr) >> 1;
            update_add_range_helper(v*2, tl, mid, l, min(r,mid));
            update_add_range_helper(v*2+1, mid+1, tr, max(l,mid+1), r);
            tree[v] = tree[v*2] + tree[v*2 + 1];
        }
    }
};

int N, Q, type, l, r, test = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &N) == 1) {
        REP(i, N) scanf("%lld", &a[i+1]);
        printf("Case #%d:\n", test++);

        SegmentTree<int> seg(N);

        seg.build(a);

        REP(i, N) {
            printf("%d ", seg.sum(i+1, i+1));
        }
        printf("\n");

        scanf("%d", &Q);
        REP(i, Q) {
            scanf("%d%d%d", &type, &l, &r);
            if(type == 0) {
                seg.update_range(1, 0, N, l, r);
            } else {
                printf("%lld\n", seg.sum(l, r));
            }
        }
    }
    return 0;
}
