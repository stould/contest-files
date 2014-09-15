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

int N, M;

int main(void) {
	scanf("%d%d", &N, &M);
	vector<pair<int, int> > vi(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &vi[i].first);
		vi[i].second = i + 1;
	}

	for ( ; vi.size() > 1; ) {
		int p = vi[0].first - M;
		int id = vi[0].second;
		vi.erase(vi.begin());
		if (p > 0) {
			vi.push_back(make_pair(p, id));
		}
	}
	cout << vi[0].second << endl;
    return 0;
}
