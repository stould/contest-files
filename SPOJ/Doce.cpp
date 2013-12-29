#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x...) printf(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _foreach(it, b, e) for(__typeof__(b) it = (b); it != (e); ++it)
#define foreach(x...) _foreach(x)

typedef long long int Int;

const int INF = 0x3f3f3f;
const Int hugeinf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;

const int MAXN = 100005;

int N, M;

Int dp[MAXN];
Int best[MAXN];

int mt[MAXN];

Int fd[MAXN];

int main(void) {
	int i, j;

	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		for (i = 0; i < N; i++) {
			best[i] = 0LL;
			for (j = 0; j < M; j++) {
				scanf("%d", &mt[j]);
			}
			dp[M - 1] = dp[M] = dp[M + 1] = 0;
			for (j = M - 1; j >= 0; j--) {
				dp[j] = max(dp[j + 1], dp[j + 2] + mt[j]);
			}
			best[i] = dp[0];
		}
		fd[N - 1] = fd[N] = fd[N+1] = 0;
		for (i = N - 1; i >= 0; i--) {
			fd[i] = max(fd[i + 1], fd[i + 2] + best[i]);
		}

		printf("%lld\n", fd[0]);
	}
	return 0;
}

