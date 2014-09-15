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

const int MAXP = 15;
const int MAXN = 1000005;

int N, M;
int P[MAXP];

int dp[MAXN];

int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2; ) {
		for (int i = 0; i < M; i++) {
			scanf("%d", &P[i]);
		}
		for (int i = N; i >= 0; i--) {
			dp[i] = 0;
			for (int k = 0; k < M; k++) {
				if (i + P[k] <= N && !dp[i + P[k]]) { 					
					dp[i] = !dp[i + P[k]];
					break;
				}
			}			
		}

		int ans = dp[0];

		if (ans) {
			puts("Stan wins");
		} else {
			puts("Ollie wins");
		}
	}
    return 0;
}
