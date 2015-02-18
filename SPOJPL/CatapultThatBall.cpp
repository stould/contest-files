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

const int MAXN = 50002;
const int INF = 1000000009;

int arry[MAXN];
int tree[4 * MAXN];

int N, M;

void build(int node, int l, int r) {
    if (l > r) {
        return;
    }
    if (l == r) {
        tree[node] = arry[l];
    } else {
        int m = (l + r) / 2;
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int node, int l, int r, int bound_l, int bound_r) {
    if (bound_l > bound_r) {
        return -INF;
    }
    if (l >= bound_l && r <= bound_r) {
        return tree[node];
    }
    int m = (l + r) / 2;

    int a = query(2 * node, l, m, bound_l, min(m, bound_r));
    int b = query(2 * node + 1, m + 1, r, max(bound_l, m + 1), bound_r);

    return max(a, b);
}

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    int a, b, i;

    for ( ; scanf("%d%d", &N, &M) == 2; ) {
        for (i = 0; i < 4 * N; i++) tree[i] = 0;
        for (i = 0; i < N; i++) {
            arry[i] = in();
        }

        build(1, 0, N - 1);
        for(int i = 0; i < 4*N+1; i++)
            cout << tree[i] << endl;
        cout << endl;

        int ans = 0;

        for (i = 0; i < M; i++) {
            a = in();
            b = in();

            a -= 1;
            b -= 1;

            int q = query(1, 0, N - 1, a, b - 1);

            //printf("%d\n", q);

            if (q <= arry[a]) {
                ans += 1;
            }
        }

   //     printf("%d\n", ans);
    }
    return 0;
}

