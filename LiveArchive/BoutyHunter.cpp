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

const int MAXN = 530;
const double INF = 10010101001010.0;

int T;
int N;
int X[MAXN], Y[MAXN];
double dp[MAXN][MAXN];
//int mark[MAXN][MAXN];
double dist[MAXN][MAXN];

double func(int p1, int p2) {
	int next = 1 + max(p1, p2);
	
	if (next == N - 1) {
		return dist[p1][next] + dist[p2][next];
	} else {
		double& ans = dp[p1][p2];
		
		if (ans < 0.0) {
			ans = INF;

			chmin(ans, dist[p1][next] + func(next, p2));
			chmin(ans, dist[p2][next] + func(p1, next));
		}
		
		return ans;
	}
}

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i];
			for (int j = 0; j < N; j++) {
				dist[i][j] = dist[j][i] = hypot(X[i] - X[j], Y[i] - Y[j]);
			}
		}
		
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				dp[i][j] = -1.0;
				//mark[i][j] = false;
			}
		}
		
		double ans = func(0, 0);

		cout << fixed << setprecision(12) << ans << "\n";
	}
	
	return 0;
}
