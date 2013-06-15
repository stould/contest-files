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

int in() { int x; scanf("%d", &x); return x; }

const int INF = 100010101;
const int MAXN = 1000009;
int T, E, P, J, acc, now, v[MAXN];
char name[25], best[25];

int naive(int a, int b) {
    int i, min_a = INT_MAX, max_a = INT_MIN;

    for (i = a; i <= b; i++) {
        min_a = min(min_a, v[i]);
        max_a = max(max_a, v[i]);
    }
    return min_a + max_a;
}

pair<int, int> tree[MAXN*4];

void build(int a[], int v, int tl, int tr){
    if (tl == tr) {
        tree[v].first = a[tl];
        tree[v].second = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build (a, 2 * v, tl, tm);
        build (a, 2 * v + 1, tm + 1, tr);
        tree[v].first = min (tree[2 * v].first, tree[2 * v + 1].first);
        tree[v].second = max (tree[2 * v].second, tree[2 * v + 1].second);
    }
}

int rmq_min(int v, int tl, int tr, int l, int r){
    if (l > r) {
        return INF;
    }
    if (tl == l && tr == r) {
        return tree[v].first;
    } else {
        int tm = (tl + tr) >> 1;
        return min(rmq_min(2 * v, tl, tm, l, min(tm, r)),rmq_min(2 * v + 1,tm + 1, tr, max(l ,tm + 1), r));
    }
}

int rmq_max(int v, int tl, int tr, int l, int r){
    if (l > r) {
        return -INF;
    }
    if (tl == l && tr == r) {
        return tree[v].second;
    } else {
        int tm = (tl + tr) >> 1;
        return max(rmq_max(2 * v, tl, tm, l, min(tm, r)), rmq_max(2 * v + 1,tm + 1, tr, max(l ,tm + 1), r));
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    T = in();

    int i;

    for ( ; T--; ) {
        E = in(), P = in(), J = in();

        acc = INT_MIN;

        for ( ; E--; ) {
            scanf("%s", name);

            now = 0;

            for (i = 0; i < P; i++) {
                v[i] = in();
            }

            build(v, 1, 0, MAXN);

            for (i = 0; i + J <= P; i++) {
                now += rmq_min(1, 0, MAXN, i, i + J - 1);
                now += rmq_max(1, 0, MAXN, i, i + J - 1);
            }

            if (now > acc) {
                acc = now;
                strcpy(best, name);
            }
        }

        printf("%s %d\n", best, acc);
    }
    return 0;
}
