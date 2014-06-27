/*
ID: jeferso1
LANG: C++
TASK: clocks
*/
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>

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

int C[10];
vector<int> move[10];

void build(void) {
	move[1].push_back(0); move[1].push_back(1); 
	move[1].push_back(3); move[1].push_back(4);

	move[2].push_back(0); move[2].push_back(1);
	move[2].push_back(2);
	
	move[3].push_back(1); move[3].push_back(2);
	move[3].push_back(4); move[3].push_back(5);

	move[4].push_back(0); move[4].push_back(3);
	move[4].push_back(6);

	move[5].push_back(1); move[5].push_back(3);
	move[5].push_back(4); move[5].push_back(5);
	move[5].push_back(7);

	move[6].push_back(2); move[6].push_back(5);
	move[6].push_back(8);

	move[7].push_back(3); move[7].push_back(4);
	move[7].push_back(6); move[7].push_back(7);

	move[8].push_back(6); move[8].push_back(7);
	move[8].push_back(8);

	move[9].push_back(4); move[9].push_back(5);
	move[9].push_back(7); move[9].push_back(8);
}

int fix(int x) {
	int p = (x + 3) % 12;
	if (p == 0) p = 12;
	return p;
}

vector<int> apply(vector<int> vs, int p) {
	vector<int> ans;
	for (int i = 0; i < 9; i++) {
		if (binary_search(move[p].begin(), move[p].end(), i)) {
			ans.push_back(fix(vs[i]));
		} else {
			ans.push_back(vs[i]);
		}
	}
	return ans;
}


bool done(vector<int> vs) {
	for (int i = 0; i < 9; i++) {
		if (vs[i] != 12) return false;
	}
	return true;
}

vector<int> func(vector<int> vs) {
	queue<pair<vector<int>, pair<int, string> > > q;
	q.push(make_pair(vs, make_pair(1, "")));

	set<vector<int> > s;

	for ( ; !q.empty(); ) {
		vector<int> vt = q.front().first;
		int id = q.front().second.first;
		string bf = q.front().second.second;
		q.pop();
		s.insert(vt);
		if (done(vt)) {
			vector<int> ans;
			for (int i = 0; i < (int) bf.size(); i++) {
				ans.push_back(bf[i] - '0');
			}
			return ans;
		}
		if (id > 9) continue;
		vector<int> vp = vt;
		for (int i = 0; i <= 4; i++) {				
			vp = apply(vt, id);			
			if (s.count(vp)) continue;
			q.push(make_pair(vp, make_pair(id + 1, bf + char('0' + i))));
		}
	}	
}

int main(void) {
	//	freopen("clocks.in", "r", stdin);
	//	freopen("clocks.out", "w", stdout);
	build();
	vector<int> vs(9);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &vs[i]);
	}

	vector<int> ans = func(vs);

	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
    return 0;
}
