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
const int INF = INT_MAX / 3;

int N, M, K;
int dp[MAXN][MAXN];

int main(void) {
	int test = 1;
	int A, B, C;
	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		for (int i = 1; i <= N; i++) {
			fill(dp[i], dp[i] + N + 1, -INF);
		}

		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &A, &B, &C);
			dp[A][B] = dp[B][A] = C;
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {					
					dp[i][j] = max(dp[i][j], max(dp[i][k], dp[k][j]));
				}
			}
		}

		scanf("%d", &K);
		printf("Instancia %d\n", test++);
		for ( ; K--; ) {
			scanf("%d%d", &A, &B);			
			printf("%d\n", dp[A][B]);
		}
	}
    return 0;
}
