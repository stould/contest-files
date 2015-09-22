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
const ll INF = 100100010010010100LL;

int T, N, A, B, Q;

struct data {
    ll sum, pref, suff, ans, cnt, pref_cnt, suff_cnt, len;

	data() {
		sum = pref = suff = ans = cnt = pref_cnt = suff_cnt = len = -INF;
	}
};

void info(data d) {
	cout << "ans " << d.ans << " " << " pref " << d.pref << " suff " << d.suff << endl;
}

data t[4*MAXN];

data combine (data l, data r) {
	data res;

	res.sum = l.sum + r.sum;
	res.len = l.len + r.len;

	res.pref = l.pref;
    res.pref_cnt = l.pref_cnt;
	
	if (res.pref <= l.sum + r.pref) {
		res.pref = l.sum + r.pref;
		res.pref_cnt = l.len + r.pref_cnt;
	}
	
	res.suff = r.suff;
	res.suff_cnt = r.suff_cnt;
	
	if (res.suff <= r.sum + l.suff) {
		res.suff = r.sum + l.suff;
		res.suff_cnt = r.len + l.suff_cnt;
	}

	if (res.ans < l.ans || (res.ans == l.ans && res.cnt < l.cnt)) {
		res.ans = l.ans;
		res.cnt = l.cnt;
	}

	if (res.ans < r.ans || (res.ans == r.ans && res.cnt < r.cnt)) {
		res.ans = r.ans;
		res.cnt = r.cnt;		
	}

	if (res.ans < res.sum || (res.ans == res.sum && res.cnt < res.len)) {
		res.ans = res.sum;
		res.cnt = res.len;
	}

	if (res.ans < res.pref || (res.ans == res.pref && res.cnt < res.pref_cnt)) {
		res.ans = res.pref;
		res.cnt = res.pref_cnt;
	}

	if (res.ans < res.suff || (res.ans == res.suff && res.cnt < res.suff_cnt)) {
		res.ans = res.suff;
		res.cnt = res.suff_cnt;
	}

	if (res.ans < l.suff + r.pref || (res.ans == l.suff + r.pref && res.cnt < res.pref_cnt + r.suff_cnt)) {
		res.ans = l.suff + r.pref;
		res.cnt = l.suff_cnt + r.pref_cnt;
	}

	return res;
}

data make_data (int val) {
	data res;

	res.sum = res.ans = res.pref = res.suff = val;
	res.cnt = res.pref_cnt = res.suff_cnt = res.len = 1LL;
	
	return res;
}

data dummy_data() {
	data res;
	res.sum = res.ans = res.pref = res.suff = -INF;
	res.cnt = res.pref_cnt = res.suff_cnt = res.len = 0LL;
	return res;
}

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) {
        t[v] = make_data(a[tl]);
	} else {
		int tm = (tl + tr) / 2;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

data query(int node, int l, int r, int bl, int br) {
	if (l > br || r < bl || l > r) {
		return dummy_data();
	} else if (l >= bl && r <= br) {
		return t[node];
	}
	
	int m = (l + r) / 2;

	data a = query(2 * node, l, m, bl, br);
	data b = query(2 * node + 1, m + 1, r, bl, br);
	
	if (a.ans <= -INF) {
		return b;
	}
	if (b.ans <= -INF) {
		return a;
	}
	
	return combine(a, b);
}

int a[MAXN];

int main(void) {
    scanf("%d", &T);

    for ( ; T--; ) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }		

		build(a, 1, 0, N - 1);

		scanf("%d", &Q);
		
        for (int i = 0; i < Q; i++) {
            scanf("%d%d", &A, &B);

            if (A > B) swap(A, B); A--; B--;

            data ans = query(1, 0, N - 1, A, B);
			
            printf("%lld %lld\n", ans.ans, ans.cnt);
        }
    }

    return 0;
}
