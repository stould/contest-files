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

const int MAXN = 220;
const int INF = INT_MAX / 4;

int N;
int F[MAXN], P[MAXN], S[MAXN], D[MAXN];
int dp[MAXN][MAXN];


int func(int id, int used) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][used];

		if (ans == -1) {
			ans = INF;

			for (int i = 0; i <= 10; i++) {
				int curr_cost = i * P[id] + (used + i) * S[id];

				if (i > 0) {
					curr_cost += F[id];
				}
				if (used + i >= D[id]) {
					chmin(ans, curr_cost + func(id + 1, used + i));
				}
			}
		}
		
		return ans;
	}
}

int main(void) {
	int test = 1;
	
	for ( ; cin >> N && N != 0; ) {
		for (int i = 0; i < N; i++) {
			cin >> F[i] >> P[i] >> S[i] >> D[i];
		}
		
		memset(dp, -1, sizeof(dp));
		
		int ans = func(0, 0);
		
		cout << "Instancia #" << test++ << endl << ans << endl;
	}
	return 0;
}
