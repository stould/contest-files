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

const int MAXN = 20;
const int INF = 10101001;

int N, W, K;
int Wei[MAXN];
int dp[(1 << 17)][101][7];

/*
int dp[(1 << 17)];
int MW[(1 << 17)];

int func(int mask) {
	if (mask == (1 << N) - 1) {
		return 0;
	} else {
		int& ans = dp[mask];

		if (ans == -1) {
			ans = INF;
			
			for (int i = 1; i < (1 << N); i++) {
				if ((mask & i) == 0 && __builtin_popcount(i) <= K && MW[i] <= W) {
					int next_mask = mask | i;

					chmin(ans, (next_mask == ((1 << N) - 1)) ? 1 : 2 + func(next_mask));
				}
			}
		}
		return ans;
	}
}

*/
	   
int func(int mask, int w, int pass) {
	if (mask == (1 << N) - 1) {
		return pass > 0 ? 1 : 0;
	} else {
		int& ans = dp[mask][w][pass];

		if (ans == -1) {
			ans = INF;
			if (pass > 0) {
				ans = min(ans, 2 + func(mask, 0, 0));
			}
			for (int i = 0; i < N; i++) {
				if (!(mask & (1 << i))) {
					if (Wei[i] + w <= W && pass + 1 <= K) {
						chmin(ans, func(mask | (1 << i), w + Wei[i], pass + 1));
					}
				}
			}
		}
		return ans;
	}
}


int main(void) {
	while (cin >> N >> W >> K) {
		for (int i = 0; i < N; i++) {
			cin >> Wei[i];
		}

		/*		memset(MW, 0, sizeof(MW));
		
		for (int i = 0; i < (1 << N); i++) {
			for (int j = 0; j < N; j++) {
				if (i & (1 << j)) {
					MW[i] += Wei[j];
				}
			}
		}
		*/

		sort(Wei, Wei + N);

		W -= Wei[0];
		K -= 1;
		for (int i = 0; i < N; i++) {
			cout << Wei[i] << " ";						 
		}
		cout << endl;
		
		memset(dp, -1, sizeof(dp));
		
		int ans = func(1, 0, 0);
		
		if (ans >= INF) ans = -1;
		
		cout << ans << "\n";
	}
	return 0;
}
