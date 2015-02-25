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

const int MAXN = 1010;

int N, M[MAXN];
int G[MAXN][MAXN];
Int dp[MAXN];
int deg[MAXN];
vector<int> des[MAXN];

int main(void) {
	bool first = true;
	
	for ( ; scanf("%d", &N) == 1; ) {
		if (!first) printf("\n");

		first = false;
		
		for (int i = 0; i <= N; i++) {
			dp[i] = 0LL;
			deg[i] = 0;
			des[i].clear();

			for (int j = 0; j <= N; j++) {
				G[i][j] = false;
			}
		}
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &M[i]);

			for (int j = 0; j < M[i]; j++) {
				scanf("%d", &G[i][j]);
				des[G[i][j]].push_back(i);
				deg[i] += 1;
			}
		}
		
		dp[0] = 1LL;
		
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < (int) des[i].size(); j++) {
				dp[i] += dp[des[i][j]];
			}
		}

		Int ans = 0LL;

		for (int i = 0; i < N; i++) {
			if (deg[i] == 0) {
				ans += dp[i];
			}
		}
		printf("%lld\n", ans);
	}
	
    return 0;
}
