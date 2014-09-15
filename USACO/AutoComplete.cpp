#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>

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

int W, N;
string S;
vector<pair<string, int> > vs;

bool func(string s, string q) {
	if (q.size() < s.size()) return false;
	if (q.substr(0, s.size()) == s) return true;
	return false;
}

int main(void) {
	freopen("auto.in", "r", stdin);
	freopen("auto.out", "w", stdout);

	cin >> W >> N;

	for (int i = 0; i < W; i++) {
		cin >> S;
		
		vs.push_back(make_pair(S, i));
	}

	sort(vs.begin(), vs.end());

	for (int i = 0; i < N; i++) {
		int K;
		cin >> K >> S;	

		K -= 1;
		
		int pos = lower_bound(vs.begin(), vs.end(), make_pair(S, 0)) - vs.begin();
		
		if (pos + K < W && func(S, vs[pos + K].first)) {
			cout << vs[pos + K].second + 1 << "\n";
		} else {
			cout << "-1\n";
		}
	}

    return 0;
}
