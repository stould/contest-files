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

const int MAXN = 1005;

int N;
pair<int, int> P[MAXN];
int dp[MAXN][3660];

int func(int id, int last) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][last];

		if (ans == -1) {
			ans = func(id + 1, last);

			if (P[id].first >= last) {
				chmax(ans, P[id].second - P[id].first + func(id + 1, P[id].second));
			}				
		}

		return ans;
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + N);

	memset(dp, -1, sizeof(dp));

	cout << func(0, 1) << endl;
	
	return 0;
}
