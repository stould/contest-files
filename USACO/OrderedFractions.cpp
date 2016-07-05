/*
  ID: jeferso1
  LANG: C++
  TASK: frac1
*/

#include <bits/stdc++.h>

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

int N;

bool comp(pair<int, int> a, pair<int, int> b) {
	return (a.first / (double) a.second) < (b.first / (double) b.second);
}

int main(void) {
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	
	scanf("%d", &N);

	vector<pair<int, int> > vp;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (gcd(i, j) != 1) continue;
			vp.push_back(make_pair(j, i));
		}
	}

	vp.push_back(make_pair(1, 1));

	sort(vp.begin(), vp.end(), comp);

	for (vector<pair<int, int> >::iterator it = vp.begin(); it != vp.end(); it++) {
		printf("%d/%d\n", it->first, it->second);
	}
	
	return 0;
}
