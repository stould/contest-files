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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned uint;

const int MAXN = 500005;
int N, M;
map<int, int> dp;

int main(void) {
	cin >> N >> M;

	queue<int> q;
	q.push(N);

	dp[N] = 0;

	while (!q.empty()) {
		int val = q.front();
		q.pop();

		if (val == M) {
			break;
		}

		if (dp.find(val / 2) == dp.end() or dp[val / 2] > dp[val] + 1) {
			dp[val / 2] = dp[val] + 1;
			q.push(val / 2);
		}
		if (dp.find(val / 3) == dp.end() or dp[val / 3] > dp[val] + 1) {
			dp[val / 3] = dp[val] + 1;
			q.push(val / 3);
		}
		if (dp.find(val * 2) == dp.end() or dp[val * 2] > dp[val] + 1) {
			dp[val * 2] = dp[val] + 1;
			q.push(val * 2);
		}
		if (dp.find(val * 3) == dp.end() or dp[val * 3] > dp[val] + 1) {
			dp[val * 3] = dp[val] + 1;
			q.push(val * 3);
		}
		if (dp.find(val - 7) == dp.end() or dp[val - 7] > dp[val] + 1) {
			dp[val - 7] = dp[val] + 1;
			q.push(val - 7);
		}
		if (dp.find(val + 7) == dp.end() or dp[val + 7] > dp[val] + 1) {
			dp[val + 7] = dp[val] + 1;
			q.push(val + 7);
		}
	}

	cout << dp[M] << endl;

	return 0;
}
