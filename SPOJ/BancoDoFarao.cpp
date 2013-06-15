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

using namespace std;

typedef long long ll;
typedef unsigned uint;

const int MAXN = 100007;

struct data {
    ll sum, pref, suff, ans;
    int l, r;
};

data t[3*MAXN];

data combine (data l, data r) {
	data res;
	res.sum = l.sum + r.sum;
	res.pref = max (l.pref, l.sum + r.pref);
	res.suff = max (r.suff, r.sum + l.suff);
	res.ans = max (max (l.ans, r.ans), l.suff + r.pref);

	return res;
}

data make_data (int val) {
	data res;
	res.sum = val;
	res.pref = res.suff = res.ans = max(-1000000, val);
	return res;
}

void build (int a[], int v, int tl, int tr) {
	if (tl == tr) {
        t[v] = make_data(a[tl]);
	} else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

data query (int v, int tl, int tr, int l, int r) {
	if (l == tl && tr == r) {
		return t[v];
	}

	int tm = (tl + tr) / 2;

	if (r <= tm) {
		return query (v*2, tl, tm, l, r);
	}
	if (l > tm) {
		return query (v*2+1, tm+1, tr, l, r);
	}
	return combine (
		query (v*2, tl, tm, l, tm),
		query (v*2+1, tm+1, tr, tm+1, r)
	);
}

int T, N, A, B, Q;
int a[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &T);

    int i;

    for ( ; T--; ) {
        scanf("%d", &N);

        for (i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }

        build(a, 1, 0, N);

        scanf("%d", &Q);

        for (i = 0; i < Q; i++) {
            scanf("%d%d", &A, &B);

            if (A > B) swap(A, B); A--; B--;

            printf("%d\n", query(1, 0, N, A, B).ans);
        }
    }

    return 0;
}
