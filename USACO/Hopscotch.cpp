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

const int MAXN = 17;

int N, M;
char S[MAXN][MAXN];
Int dp[MAXN][MAXN];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int main(void) {
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", S[i]);
	}

	dp[0][0] = 1LL;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int a = i + 1; a < N; a++) {
				for (int b = j + 1; b < M; b++) {
					if (S[i][j] != S[a][b]) {
						dp[a][b] += dp[i][j];
					}
				}
			}
		}
	}

	printf("%lld\n", dp[N-1][M-1]);
	
    return 0;
}
