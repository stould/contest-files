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

const int MAXN = 220;

int T, N;
string S;
int val[MAXN][MAXN];
int dp[MAXN][MAXN];

int func(int l, int r) {
	if (l > r) {
		return 0;
	} else if (l == r) {
		return val[l][r];
	} else {
		int& ans = dp[l][r];

		if (ans == -1) {
			ans = val[l][r];
			
			for (int i = l; i < r; i++) {
				chmax(ans, func(l, i) + func(i + 1, r));
			}
		}

		return ans;
	}
}

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N >> S;

		memset(val, 0, sizeof(val));
		
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = i; j < N; j++) {
				if (S[j] == '0') {
					cnt -= 1;
				} else  {
					cnt += 1;
				}
				if (cnt > 0) {
					val[i][j] = j - i + 1;
				}
			}
		}

		memset(dp, -1, sizeof(dp));

		cout << func(0, N - 1) << "\n";
	}
	return 0;
}
