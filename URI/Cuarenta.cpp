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

const int INF = INT_MAX / 3;
const int BEST = (int) pow(2.0, 31) - 1;

int T, N, K;
/*
int func(int id, int used) {
	if (id >= N) {
		if (used >= K) {
			return BEST;
		} else {
			return 0;
		}
	} else {
		int& ans = dp[id][used];

		if (ans == -1) {
			ans = func(id + 1, used);

			chmax(ans, P[id] & func(id + 1, used + 1));
		}
		return ans;
	}
}
*/
int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N >> K;
		vector<int> P(N);
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		int ans = 0;
		for (int i = 30; i >= 0; i--) {
			int used = 0;
			vector<int> u;
			for (int j = 0; j < (int) P.size(); j++) {
				if ((1 << i) & P[j]) {
					u.push_back(P[j]);
					used += 1;
				}
			}
			if (used >= K) {
				P = u;
			}
		}
		
		for (int i = 0; i < (1 << (int) (P.size())); i++) {
			if (__builtin_popcount(i) < K) continue;
			int s = -1;

			for (int j = 0; j < (int) P.size(); j++) {
				if (s == -1) s = P[j];
				else s &= P[j];				
			}
			chmax(ans, s);
		}
		cout << ans << "\n";
		/*		memset(dp, -1, sizeof(dp));
		int ans = func(0, 0);
		cout << ans << "\n";
		*/
	}
    return 0;
}
