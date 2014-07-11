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

int N, P[1010];
int dp[1010][550];
int goal;

int func(int id, int sum, int buff) {
	if (id == N) {
		return sum == goal ? buff : 0;
	} else {
		int& ans = dp[id][sum];
		
		if (ans == -1) {
			ans = 0;
			ans = max(ans, func(id + 1, 0, 0));
			ans = max(ans, func(id + 1, sum, buff));				
			if (P[id] <= goal) {
				ans = max(ans, func(id + 1, P[id], 1));
			}

			if (sum == goal) {
				ans = max(ans, buff + func(id + 1, 0, 0));
				if (P[id] <= goal) {
					ans = max(ans, buff + func(id + 1, P[id], 1));
				}
			} else {
				if (sum + P[id] <= goal) {
					ans = max(ans, func(id + 1, sum + P[id], buff + 1));
				}
			}
		}

		return ans;
	}
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		set<int> fs;
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
			fs.insert(P[i]);
		}
		int ans = 1;

		for (auto& i: fs) {
			memset(dp, -1, sizeof(dp));
			goal = i;
			int now = func(0, 0, 0);
			printf("P = %d %d\n", i, now);
			chmax(ans, now);
		}

		printf("T = %d\n", ans);
	}

    return 0;
}
