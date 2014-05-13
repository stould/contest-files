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

const Int INF = 101010101010101010LL;
int T;
Int P;
Int H[6], D[6], C[6];
pair<Int, Int> dp[6][1010];
pair<Int, Int> glob;

void compare(pair<Int, Int>& a, pair<Int, Int> b) {
	if (a.second >= P) {
		if (b.second < P) return;

		if (b.first < a.first || (b.first == a.first && b.second < a.second)) {
			a = b;
		}
	} else {
		//		if (b.second < P) return;
		if (b.second > a.second) {
			a = b;
		}
	}
}

pair<Int, Int> func(int id, int hit, Int a, Int b) {
	if (b >= P) {
		if (a < glob.first || a == glob.first && b < glob.second) {
			glob = make_pair(a, b);
		}		
	}
	if (id == 5) {
		return make_pair(0, 0);		
	} else {
		pair<Int, Int>& ans = dp[id][hit];
		if (ans.first == -1LL) {
			for (int i = 0; i <= H[id]; i++) {
				pair<Int, Int> tmp = func(id + 1, i, a + i * C[id], b + i * D[id]);
				tmp.first += i * C[id];
				tmp.second += i * D[id];			
				compare(ans, tmp);
			}
		}	
		return ans;
	}
}

int main(void) {
	cin >> T;
	for ( ; T--; ) {
		cin >> P;
		for (int i = 0; i < 5; i++) {
			cin >> H[i] >> D[i] >> C[i];
		}
		for (int i = 0; i < 5; i++) {
			//			dp[i] = make_pair(-1, -1);
			fill(dp[i], dp[i] + 1010, make_pair(-1LL, -1LL));
		}
		/*
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j <= H[i]; j++) {
				if (i == 0) {
					dp[i][j] = make_pair(j * C[i], j * D[i]);
				} else {
					dp[i][j] = make_pair(-INF, -INF);
					for (int k = 0; k <= H[i - 1]; k++) {
						pair<Int, Int> bf = dp[i - 1][k];
						bf.first += C[i] * j;
						bf.second += D[i] * j;

						if (bf.second > dp[i][j].second || (bf.second == dp[i][j].second && bf.first < dp[i][j].second)) {
							dp[i][j] = bf;
						}
					}					
				}
			}
		}
		pair<Int, Int> ans = make_pair(INF, INF);
		for (int i = 0; i <= H[4]; i++) {
			if (dp[4][i].second >= P) {
				if (dp[4][i].first < ans.first || (dp[4][i].first == ans.first && dp[4][i].second < ans.second)) {
					ans = dp[4][i];
				}
			}
		}
		*/
		glob = make_pair(INF, INF);
		pair<Int, Int> ans = func(0, 0, 0, 0);
		ans = glob;
		//		cout << ans.first << " " << ans.second << "\n";
		if (ans.second < INF && ans.second >= P) {
			cout << ans.first << " " << ans.second << "\n";
		} else {
			cout << "We are doomed!!\n";
		}
	}
    return 0;
}
