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


int N, M;
int P[102][16], D[102];

Int     dp[102][1 << 15][2];
short mark[102][1 << 15][2];

Int func(int id, int mask, int used) {
	if (mask == (1 << M) - 1) {
		return used * D[id];
	} else if (id == N) {
		return 1001010100001010LL;
	} else {		
		Int& ans = dp[id][mask][used];
		
		if (!mark[id][mask][used]) {
			mark[id][mask][used] = true;
			
			ans = func(id + 1, mask, 0) + used * D[id];
			
			for (int i = 0; i < M; i++) {
				if (!(mask & (1 << i))) {
					ans = min(ans, P[id][i] + func(id, mask | (1 << i), 1));
				}
			}			
		}

		return ans;
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &D[i]);
		
		for (int j = 0; j < M; j++) {
			scanf("%d", &P[i][j]);
		}
	}

	Int ans = func(0, 0, 0);

	printf("%lld\n", ans);
	
    return 0;
}
