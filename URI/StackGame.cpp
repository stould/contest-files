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

const int MAXN = 105;

int N;
int A[MAXN], B[MAXN], C[MAXN];

int dp[MAXN][MAXN][MAXN];

int func(int i, int j, int k) {
	if (i > N || j > N || k > N) {
		return 0;
	} else if (i == N && j == N && k == N) {
		return 1;
	} else {
		int& ans = dp[i][j][k];

		if (ans == -1) {
			ans = 0;

			if ((A[i] + B[j] + C[k]) % 3 == 0) {
				ans |= func(i + 1, j + 1, k + 1);
			}
			if (A[i] % 3 == 0) {
				ans |= func(i + 1, j, k);
			}
			if (B[j] % 3 == 0) {
				ans |= func(i, j + 1, k);
			}
			if (C[k] % 3 == 0) {
				ans |= func(i, j, k + 1);
			}
			if ((A[i] + B[j]) % 3 == 0) {
				ans |= func(i + 1, j + 1, k);
			}
			if ((A[i] + C[k]) % 3 == 0) {
				ans |= func(i + 1, j, k + 1);
			}
			if ((C[k] + B[j]) % 3 == 0) {
				ans |= func(i, j + 1, k + 1);
			}


		}

		return ans;
	}
}

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		for (int i = 0; i < N; i++) {
			cin >> A[i] >> B[i] >> C[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << func(0, 0, 0) << "\n";
	}
    return 0;
}
