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

const int INF = 100101010;

int N, K;

int T[110];
int C[110];
int V[110];

int dp[110][200010];

int rec(int id, int sum) {
	if (id == N) {
		if (sum == 0) {
			return 0;
		} else {
			return -INF;
		}
	}

	int& ans = dp[id][sum + 100001];

	if (ans == -1) {
		ans = T[id] + rec(id + 1, sum + V[id]);

		ans = max(ans, rec(id + 1, sum));
	}

	return ans;
}

int main(void) {
	N = in();
	K = in();

	int i;
	int j;

	for (i = 0; i < N; i++) {
		T[i] = in();
	}
	for (i = 0; i < N; i++) {
		C[i] = in();		
		C[i] *= K;

		V[i] = T[i] - C[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = rec(0, 0);
	
	printf("%d\n", ans > 0 ? ans : -1);

    return 0;
}