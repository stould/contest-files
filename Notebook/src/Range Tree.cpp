#include <bits/stdc++.h>
using namespace std;
// number type for coordinates, and its maximum value
const int MAXN = 100000;
struct per {
	int i; pair<int, int> p;
	per() {}
	per(int a, int b, int c) : i(a + 1), p(b + c, b - c) {}
	per(int yy) : i(0), p(0, yy) {}
	bool operator < (per o) const { return p.second != o.p.second? p.second < o.p.second : i < o.i; }
};

multiset<per> ts[MAXN << 2];
vector<per> pt[MAXN];

void build(int i, int le, int ri) {
	ts[i].clear();
	if(le == ri) {
		for(per p : pt[le])
			ts[i].insert(p);
		pt[le].clear();
		return;
	}
	int mi = (le + ri) / 2;
	build(2 * i, le, mi);
	build(2 * i + 1, mi + 1, ri);
	for(per p : ts[2 * i])
		ts[i].insert(p);
	for(per p : ts[2 * i + 1])
		ts[i].insert(p);
}

void query(int i, int le, int ri, int x1, int x2, int y1, int y2, vector<per> &v) {
	if(le > x2 || ri < x1) return;
	if(le >= x1 && ri <= x2) {
		auto it = ts[i].lower_bound(per(y1));
		while(it != ts[i].end() && it->p.second <= y2)
			v.push_back(*it++);
		return;
	}
	int mi = (le + ri) / 2;
	query(2 * i, le, mi, x1, x2, y1, y2, v);
	query(2 * i + 1, mi + 1, ri, x1, x2, y1, y2, v);
}

void ch(bool rem, int i, int le, int ri, per p) {
	if(rem) ts[i].erase(p);
	else ts[i].insert(p);
	if(le == ri) return;
	int mi = (le + ri) / 2;
	if(p.p.first <= mi) ch(rem, 2 * i, le, mi, p);
	else ch(rem, 2 * i + 1, mi + 1, ri, p);
}

void add(int i, int le, int ri, per p) { ch(false, i, le, ri, p); }
void remove(int i, int le, int ri, per p) { ch(true, i, le, ri, p); }
