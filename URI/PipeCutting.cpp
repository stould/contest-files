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

const int MAXN = 1010;
int N, T;
int C[MAXN], V[MAXN];

int dp[MAXN][2 * MAXN];

int func(int id, int len) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][len];

		if (ans == -1) {
			ans = func(id + 1, len);

			for (int i = 1; C[id] * i <= len; i++) {
				chmax(ans, V[id] * i + func(id + 1, len - C[id] * i));
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		cin >> C[i] >> V[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << func(0, T) << endl;

	return 0;
}
