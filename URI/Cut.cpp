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

const double INF = 1001010100101.0;
const int MAXN = 220;

int N;
double X[MAXN], Y[MAXN];
double dp[MAXN][MAXN];
bool seen[MAXN][MAXN];

double func(int pos, int cut) {
	if (pos >= 2 * N) {
		if (cut == N - 2) {
			return 0;
		} else {
			return INF;
		}
	} else {
		double& ans = dp[pos][cut];

		if (!seen[pos][cut]) {
			seen[pos][cut] = true;
			
			ans = func(pos + 1, cut);

			for (int i = pos + 1; i < 2 * N; i++) {
				double dst = hypot(X[pos] - X[i], Y[pos] - Y[i]);
				chmin(ans, dst + func(i, cut + 1));
			}
		}

		return ans;
	}
}

int main(void) {
	for ( ; cin >> N; ) {
		for (int i = 0; i < 2 * N; i++) {
			cin >> X[i] >> Y[i];
		}

		memset(seen, false, sizeof(seen));

		double ans = func(0, 0);

		cout << fixed << setprecision(4) << ans << endl;
	}
    return 0;
}
