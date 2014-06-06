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

int A, B, N, M;

int dp[20][(1 << 20)];
vector<int> graph[20];

int func(int x, int mask, int st) {
	if (x == st) {
		return 1;
	} else {
		int& ans = dp[x][mask];

		if (ans == -1) {
			ans = 0;

			for (int i = 0; i < (int) graph[x].size(); i++) {
				int u = graph[x][i];

				if (!(mask & (1 << u)) || u == st) {
					cout << (x + 1) << " " << (u + 1) << "\n";
					ans += func(u, mask | (1 << u), st + 1);
				}				
			}
		}

		return ans;
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		A -= 1;
		B -= 1;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	int ans = 0;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int u = graph[i][j];
			ans += func(u, (1 << i) | (1 << u), i);
		}
	}

	cout << ans << "\n";
    return 0;
}
