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
int P[110], W[110];
int dp[110][3500];

int func(int id, int w) {
	if (id == N)  {
		return 0;
	} else {
		int& ans = dp[id][w];

		if (ans == -1) {
			ans = func(id + 1, w);
			if (w - W[id] >= 0) {
				chmax(ans, P[id] + func(id + 1, w - W[id]));
			}
		}

		return ans;
	}
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i], &W[i]);
		}
		scanf("%d", &M);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", func(0, M));
	}
    return 0;
}
