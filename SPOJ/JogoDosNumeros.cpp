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

int N;
int P[MAXN];
map<int, int> dp[1010][1010];

int func(int id, int used, int sum) {
	if (sum == 0 && used > 0) return 2;

	if (id == N) {
		return ((sum == 0 && used > 0) ? 2 : 1);
	} else {
		if (dp[id][used][sum] == 0) {
			dp[id][used][sum] = 1;

			int n1 = func(id + 1, used, sum);
			
			if (n1 == 2) {
				dp[id][used][sum] = 2;
			} else {
				int n2 = func(id + 1, used + 1, sum - P[id]);

				if (n2 == 2) {
					dp[id][used][sum] = 2;
				} else {
					int n3 = func(id + 1, used + 1, sum + P[id]);

					if (n3 == 2) {
						dp[id][used][sum] = 2;
					}
				}
			}
		}
		return dp[id][used][sum];
	}
}


int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
			for (int j = 0; j < N; j++) {
				dp[i][j].clear();
			}
		}

		bool ok = false;

		int ans = func(0, 0, 0);

		if (ans == 2) ok = true;

		puts(ok ? "S" : "N");
	}
    return 0;
}
