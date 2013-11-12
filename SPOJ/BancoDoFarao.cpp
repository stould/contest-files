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

int T, N, A, B, Q;

struct data {
    ll sum, pref, suff, ans, cnt, pref_cnt, suff_cnt;
    int l, r;
};

data t[4*MAXN];

data combine (data l, data r) {
	data res;

	res.sum = l.sum + r.sum;

	//res.pref = max (l.pref, l.sum + r.pref);
	//res.suff = max (r.suff, r.sum + l.suff);

	res.pref = l.pref;
    res.pref_cnt = l.suff_cnt;

	if (res.pref < l.sum + r.pref || (res.pref == l.sum + r.pref && res.pref_cnt > l.cnt + r.pref_cnt)) {
        res.pref = l.sum + r.pref;
        res.pref_cnt = l.cnt + r.pref_cnt;
	}

	res.suff = r.suff;
	res.suff_cnt = r.suff_cnt;

	if (res.suff < r.sum + l.suff || (res.suff == r.sum + l.suff && res.suff_cnt > r.cnt + l.suff_cnt)) {
        res.suff = r.sum + l.suff;
        res.suff_cnt = r.cnt + l.suff_cnt;
	}

	res.ans = l.suff + r.pref; //max (max (l.ans, r.ans), l.suff + r.pref);
    res.cnt = l.suff_cnt + r.pref_cnt;

	if (res.ans < l.ans || (res.ans == l.ans && res.cnt > l.cnt)) {
        res.ans = l.ans;
        res.cnt = l.cnt;
	}
	if (res.ans < r.ans || (res.ans == r.ans && res.cnt > r.cnt)) {
	    res.ans = r.ans;
        res.cnt = r.cnt;
	}

	return res;
}

data make_data (int val, int pos) {
	data res;

	res.sum = val;
	res.cnt = 1;

	if (pos == 0) {
        res.pref_cnt = 0;
	} else {
        res.pref_cnt = 1;
	}

	if (pos == N - 1) {
        res.suff_cnt = 0;
	} else {
        res.suff_cnt = 1;
	}

	res.pref = res.suff = res.ans = max(-1000000, val);

	return res;
}

void build (int a[], int v, int tl, int tr) {
	if (tl == tr) {
        t[v] = make_data(a[tl], tl);
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

int a[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    scanf("%d", &T);

    int i;

    for ( ; T--; ) {
        scanf("%d", &N);

        for (i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }

        build(a, 1, 0, N - 1);

        scanf("%d", &Q);

        for (i = 0; i < Q; i++) {
            scanf("%d%d", &A, &B);

            if (A > B) swap(A, B); A--; B--;

            data ans = query(1, 0, N - 1, A, B);

            printf("%lld %lld\n", ans.ans, ans.cnt);
        }
    }

    return 0;
}
