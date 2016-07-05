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

const int MAXN = 150;

int N, M, S;
int U, V;
int P[MAXN];
bool mark[MAXN][100005];
double dp[MAXN][100005];

double dv = 1.0 / 6.0;

double func(int pos, int steps) {
	if (steps > 100000) {
		return 0.0;
	} else if (pos >= N * M) {
		return 1.0;
	} else {
		double& ans = dp[pos][steps];
		
		if (!mark[pos][steps]) {
			ans = 0.0;
			
			mark[pos][steps] = true;

			for (int i = 1; i <= 6; i++) {
				int nx = pos + i;

				if (nx >= N * M) {
					nx = N * M - i + 1;
				}

				nx = P[nx];

				ans += dv * (1 + func(nx, steps + 1));
			}
		}
		
		return ans;
	}
}

int main(void) {
	while (cin >> M >> N >> S) {
		for (int i = 0; i <= N * M; i++) {
			P[i] = i;
		}
		
		for (int i = 0; i < S; i++) {
			cin >> U >> V;
			P[U] = V;
		}
		
		memset(mark, false, sizeof(mark));

		double ans = func(1, 0);

		cout << fixed << setprecision(12) << ans << endl;
	}
	return 0;
}
