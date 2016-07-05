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

const int MAXN = 201;

int T, N, K;
Int dp[MAXN][MAXN][MAXN];

Int func(int cnt, int last, int gp) {
	if (cnt == 0) {
		return 1;
	} else {
		Int& ans = dp[cnt][last][gp];

		if (ans == -1) {
			ans = 0;

			for (int i = last; cnt - i >= 0; i++) {
				if (i < K) continue;
				ans += func(cnt - i, i, gp + 1);
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		
		memset(dp, -1, sizeof(dp));

		cout << func(N, 0, 0) << "\n";
	}
	return 0;
}
