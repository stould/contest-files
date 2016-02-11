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
typedef unsigned long long uInt;
typedef unsigned uint;

int T, N;
double A;
double dp[80][30];

double func(int id, int w) {
	if (w == N) {
		return 1.0;
	} else if (id >= 2 * N - 1) {
		return 0.0;
	} else {
		double& ans = dp[id][w];

		if (ans < 0.0) {
			ans = 0;

			ans += A * func(id + 1, w + 1);
			ans += (1 - A) * func(id + 1, w);
		}
		
		return ans;
	}
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N >> A;

		for (int i = 0; i <= 2 * N; i++) {
			for (int j = 0; j <= N; j++) {
				dp[i][j] = -1.0;
			}
		}
		
		double ans = func(0, 0);

		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}
