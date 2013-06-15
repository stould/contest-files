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

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = (int) (10e5) + 10;
int A, B, N, K, a[MAXN];
ll t[MAXN*4];
char C;

void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = (ll) a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = (ll) t[v*2] * t[v*2+1];
	}
}

ll sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 1;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return (ll) sum (v*2, tl, tm, l, min(r,tm))
		* (ll) sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = (ll) t[v*2] * t[v*2+1];
	}
}

int main(void) {
    freopen("i.in", "w", stdout);
    REP(i, (int) (10e5)) {
        printf("%d ", 100);
    }
    return 0;
}

