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
const int INF = INT_MAX / 2;

int N, M, K;
int MT[MAXN][MAXN];

char buff[110][110];
int dp[110][110];
bool memo[110][110];

int func(int lin, int pat) {
	if (lin == N) {
		return 0;
	} else {
		int& ans = dp[lin][pat];

		if (!memo[lin][pat]) {
			memo[lin][pat] = true;

			ans = -INF;

			for (int i = 0; i < K; i++) {
				int sum = 0;
				bool valid = true;
				for (int j = 0; valid && j < M; j++) {
					if (lin != 0 && buff[i][j] == buff[pat][j] && buff[i][j] != '.') {
						valid = false;
					}
					if (buff[i][j] == '+') {
						sum += MT[lin][j]; 
					} else if (buff[i][j] == '-') {
						sum -= MT[lin][j];
					}
				}
				if (valid) {
					ans = max(ans, sum + func(lin + 1, i));
				}
			}
		}	
		return ans;
	}
}

int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &MT[i][j]);
			}
		}
		scanf("%d", &K);

		for (int i = 0; i < K; i++) {
			scanf("%s", buff[i]);
		}
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				memo[i][j] = false;
			}
		}
		printf("%d\n", func(0, K));
	}
    return 0;
}
