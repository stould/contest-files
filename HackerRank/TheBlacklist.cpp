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

int N, K;
int P[11][22];
int dp[22][(1 << 11)];

int func(int id, int mask) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][mask];

		if (ans == -1) {		
			ans = INF;

			for (int i = 0; i < K; i++) {
				if (!(mask & (1 << i))) {
					int curr = 0;
					for (int j = id; j < N; j++) {
						curr += P[i][j];

						chmin(ans, curr + func(j + 1, mask | (1 << i)));
					}
				}
			}			
		}

		return ans;
	}
}

int main(void) {
	cin >> N >> K;
	
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cin >> P[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	printf("%d\n", func(0, 0));

    return 0;
}
