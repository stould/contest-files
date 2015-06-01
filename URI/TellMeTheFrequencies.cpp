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

string S;
int F[500];

bool st(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	} else {
		return a.second > b.second;
	}
}

int main(void) {
	bool done = false;
	while (getline(cin, S)) {
		if (done) cout << "\n";
		done = true;
		
		int N = (int) S.size();
		
		memset(F, 0, sizeof(F));
		
		for (int i = 0; i < N; i++) {
			F[(int) S[i]] += 1;
		}

		vector<pair<int, int> > ans;
		
		for (int i = 32; i <= 128; i++) {
			if (F[i]) {
				ans.push_back(make_pair(F[i], i));
			}
		}
		
		sort(ans.begin(), ans.end(), st);
		
		for (int i = 0; i < (int) ans.size(); i++) {
			cout << ans[i].second << " " << ans[i].first << "\n";
		}		
	}
	return 0;
}
