#include <iostream>

using namespace std;

#define MAXN 10
#define INF 10000000

int a[MAXN];
pair<int,int> t[4*MAXN];

pair<int,int> combine (pair<int,int> a, pair<int,int> b) {
	if (a.first > b.first)
		return a;
	if (b.first > a.first)
		return b;
	return make_pair (a.first, a.second + b.second);
}

pair<int,int> combine2(pair<int,int> a, pair<int,int> b) {
	if (a.first > b.first)
		return a;
	if (b.first > a.first)
		return b;
	return make_pair(a.first, a.second + b.second);
}

void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = make_pair (a[tl], 1);
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

pair<int,int> get_max (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return make_pair (-INF, 0);
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return combine (
		get_max (v*2, tl, tm, l, min(r,tm)),
		get_max (v*2+1, tm+1, tr, max(l,tm+1), r)
	);
}

pair<int,int> get_min(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return make_pair (INF, 0);
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return combine2 (
		get_min (v*2, tl, tm, l, min(r,tm)),
		get_min (v*2+1, tm+1, tr, max(l,tm+1), r)
	);
}


void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = make_pair (new_val, 1);
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}


int main(void) {
    a[0] = 0; a[1] = 1; a[2] = 2; a[3] = 3; a[4] = 4;
    a[5] = 5; a[6] = 6; a[7] = 7; a[8] = 8; a[9] = 9; a[10] = 10;
    build(a, 1, 0, MAXN-1);
 //   update(1, 0, MAXN-1, 1, 50);
 //   update(1, 0, MAXN-1, 2, 15);
  //  update(1, 0, MAXN-1, 3, 2);
  //  update(1, 0, MAXN-1, 4, 9);
  //  pair<int, int> p = get_max(1, 0, MAXN-1, 0, MAXN-1);
    pair<int, int> p = get_min(1, 0, MAXN-1, 0, MAXN-1);
    cout << p.first << "\n";
    return 0;
}

