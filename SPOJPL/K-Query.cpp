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

const int MAXN = 30000;

int N, Q;

Int v[MAXN];
Int tree[3 * MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = v[l];
    }

    int mid = (l + r) / 2;

    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int lb, int rb, int l, int r, int k) {
    if (l > r) {
        return 0;
    }
    if(l == lb && r == rb) {
        return tree[node] > k;
    }

    int mid = (lb + rb) / 2;

    int left = query(2 * node, lb, mid, l, min(r, mid), k);
    int righ = query(2 * node + 1, mid+1, rb, max(l, mid + 1), r, k);

    return left + righ;
}

int main(void) {
    N = in();

    int i;

    for (i = 0; i < N; i++) scanf("%lld", &v[i]);

    build(1, 0, N);

    Q = in();

    for ( ; Q--; ) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);

        printf("%d\n", query(1, 0, N, l, r, k));
    }
    return 0;
}
