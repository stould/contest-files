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
int dp[100005];

int funcA(int a, int b) {
	int ans = INT_MAX, curr = 0;

	while (a < b) {
		a *= 2;
		curr += 1;

		if (dp[a] != -1) {
			chmin(ans, curr + dp[a]);
		}
	}
	curr += (a - b);
	chmin(ans, curr);
	return ans;
}

int main(void) {
	cin >> N >> M;

	memset(dp, 63, sizeof(dp));
	dp[N] = 0;

	queue<int> q;
	q.push(N);

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();

		if (now == M) break;
		if (now > M) {
			chmin(dp[M], dp[now] + (now - M));
			continue;
		}

		if (dp[2 * now] > dp[now] + 1) {
			dp[2 * now] = dp[now] + 1;
			q.push(2 * now);
		}
		if (now - 1 >= 1 && dp[now - 1] > dp[now] + 1) {
			dp[now - 1] = dp[now] + 1;
			q.push(now - 1);
		}
	}	
	
	cout << dp[M] << "\n";
	
    return 0;
}
