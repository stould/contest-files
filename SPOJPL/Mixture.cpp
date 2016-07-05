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

const int MAXN = 110;

int N;
int P[MAXN];
int dp[MAXN][MAXN], sum[MAXN][MAXN];

int func(int l, int r) {
	if (l == r) {
		return 0;
	} else if (l + 1 == r) {
		return P[l] * P[l + 1];
	} else {
		int& ans = dp[l][r];

		if (ans == -1) {
			ans = INT_MAX;
			
			for (int i = l; i < r; i++) {
				ans = min(ans, (sum[l][i] * sum[i + 1][r]) + (func(l, i) + func(i + 1, r)));
			}
		}
		
		return ans;
	}
}

int main(void) {
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				if (i == j) {
					sum[i][i] = P[i];
				} else {
					sum[i][j] = sum[i][j - 1] + P[j];
				}
				sum[i][j] %= 100;
			}
		}

		cout << func(0, N - 1) << endl;
	}
	return 0;
}
