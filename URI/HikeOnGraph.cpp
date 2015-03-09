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

const int MAXN = 52;

int N, A, B, C;
char S[51][51];
int dp[51][51][51];

struct state {
	int pa, pb, pc;
};

int main(void) {
	for ( ; scanf("%d%d%d%d", &N, &A, &B, &C) == 4; ) {
		A -= 1;
		B -= 1;
		C -= 1;

		int ans = INT_MAX;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %c", &S[i][j]);
			}
		}

		memset(dp, 63, sizeof(dp));

		queue<state> q;
		q.push({A, B, C});

		dp[A][B][C] = 0;

		for ( ; !q.empty(); ) {
			state now = q.front();
			q.pop();

			if (now.pa == now.pb && now.pa == now.pc) {
				chmin(ans, dp[now.pa][now.pb][now.pc]);
				continue;
			}

			for (int i = 0; i < N; i++) {
				if (S[now.pa][i] == S[now.pb][now.pc]) {
					if (dp[i][now.pb][now.pc] > dp[now.pa][now.pb][now.pc] + 1) {
						dp[i][now.pb][now.pc] = dp[now.pa][now.pb][now.pc] + 1;
						q.push({i, now.pb, now.pc});
					}
				}
				if (S[now.pb][i] == S[now.pa][now.pc]) {
					if (dp[now.pa][i][now.pc] > dp[now.pa][now.pb][now.pc] + 1) {
						dp[now.pa][i][now.pc] = dp[now.pa][now.pb][now.pc] + 1;
						q.push({now.pa, i, now.pc});
					}
				}
				if (S[now.pc][i] == S[now.pa][now.pb]) {
					if (dp[now.pa][now.pb][i] > dp[now.pa][now.pb][now.pc] + 1) {
						dp[now.pa][now.pb][i] = dp[now.pa][now.pb][now.pc] + 1;
						q.push({now.pa, now.pb, i});
					}					
				}
			}
		}
		
		if (ans == INT_MAX) {
			puts("impossible");
		} else {
			printf("%d\n", ans);
		}
	}
    return 0;
}
