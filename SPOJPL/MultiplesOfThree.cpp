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

const int MAXN = 4;
const int INF = 10000010;

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

    //Only works if you change the routine of build and update the tree
    T prod(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return 1;
        }
        if(l == tl && r == tr) {
            return tree[v];
        }
        int mid = (tl + tr) / 2;
        return prod(v*2, tl, mid, l, min(r,mid)) * prod(v*2+1, mid+1, tr, max(l,mid+1), r);
    }

    T prod(int l, int r) {
        return prod(1, 0, N, l, r);
    }

    void update_change(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int mid = (tl + tr) >> 1;
            if(pos <= mid) {
                update_change(v*2, tl, mid, pos, new_val);
            } else {
                update_change(v*2+1, mid+1, tr, pos, new_val);
            }
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    void update_change(int pos, T new_val) {
        update_change(1, 0, N, pos, new_val);
    }

    void update_add_single(int v, int tl, int tr, int pos, T add) {
        if (tl == tr) {
            tree[v] += add;
        } else {
            int mid = (tl + tr) >> 1;
            if(pos <= mid) {
                update_add_single(v*2, tl, mid, pos, add);
            } else {
                update_add_single(v*2+1, mid+1, tr, pos, add);
            }
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    void update_add_single(int pos, T add) {
        update_add_single(1, 0, N, pos, add);
    }

    void update_add_range_helper(int v, int tl, int tr, int l, int r, T add) {
        if(l > r) {
            return;
        }
        if(l == tl && tr == r) {
            tree[v] += add;
        } else {
            int mid = (tl + tr) >> 1;
            update_add_range_helper(v*2, tl, mid, l, min(r,mid), add);
            update_add_range_helper(v*2+1, mid+1, tr, max(l,mid+1), r, add);
            tree[v] = tree[v*2] + tree[v*2 + 1];
        }
    }

    void update_add_range(int v, int tl, int tr, int l, int r, int add) {
        if(tl == l && tr == r) {
            update_add_range_helper(v, tl, tr, l + 1, r - 1, add);
            update_add_single(v, tl, tr, l, add);
        } else {
            update_add_range_helper(v, tl, tr, l, r, add);
        }
    }

    void update_add_range(int l, int r, T add) {
        update_add_range(1, 0, N, l, r, add);
    }

    int func(int v, int tl, int tr, int& ans) {
        if (tl == tr) {
            if(tree[v] % 3 == 0 || tree[v] == 0) ans += 1;
        } else {
            int mid = (tl + tr) / 2;
            func(v*2, tl, mid, ans);
            func(v*2+1, mid+1, tr, ans  );
        }
    }
};

int N, Q, T, A, B, a[100010];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &N, &Q);
    SegmentTree<int> t(N);
    REP(i, Q) {
        scanf("%d%d%d", &T, &A, &B);
        if(T == 0) {
            t.update_add_range(A, B, 1);
        } else {
            int ans = 0;
            t.func(1, A, B, ans);
            printf("%d\n", ans);
        }
    }
    return 0;
}

