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
const Int INF = 1010010101010100101LL;

int T, N, M;
Int P[MAXN];

Int dp[MAXN][MAXN][MAXN];

Int func(int now, int last, int used) {
	if (used == M && now == N) {
		return 0LL;
	}
	if (now >= N) {
		return INF;
	} else {
		Int& ans = dp[now][last][used];

		if (ans == -1) {
			ans = INF;
			
			if (used + 1 <= M) {
				for (int i = now; i < N; i++) {
					chmin(ans, P[i] - P[last] + func(i + 1, i + 1, used + 1));
				}
			}
		}

		return ans;
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		sort(P, P + N);

		memset(dp, -1LL, sizeof(dp));

		cout << "Case #" << t << ": " << func(0, 0, 0) << "\n";
	}
    return 0;
}
