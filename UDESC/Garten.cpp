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

const int MAXN = 600;

int T;
int N;
int S[MAXN];
int dp[MAXN][MAXN];

int func(int id, int used) {
	if (id > N) {
		return 0;
	} else {
		int& ans = dp[id][used];

		if (ans == -1) {
			ans = func(id + 1, used);

			if (used < id / 2 or id == 1) {
				chmax(ans, S[id] + func(id + 1, used + 1));
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> S[i];
		}

		memset(dp, -1, sizeof(dp));
		
		int ans = func(1, 0);
		
		cout << "Maratona #" << t << ": " << ans << endl;
	}
	return 0;
}
