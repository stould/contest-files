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

const int MAXN = 120;
const int INF = INT_MAX / 3;

int N;
int P[MAXN], S[MAXN];

int dp[MAXN][MAXN];
bool mark[MAXN][MAXN];

int func(int a, int b) {
	if (a > b) {
		return 0;
	} else if (a == b) {
		return P[a];
	} else {
		int& ans = dp[a][b];

		if (!mark[a][b]) {
			mark[a][b] = true;
			ans = -INF;

			for (int i = 0; i <= (b - a); i++) {
				int ls = S[a + i] - S[a - 1];
				int rs = S[b] - S[b - i - 1];
				
				chmax(ans, max(ls - func(a + i + 1, b), rs - func(a, b - i - 1)));
			}
		} 

		return ans;
	}   
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 1; i <= N; i++) {
			scanf("%d", &P[i]);
			S[i] = S[i - 1] + P[i];
		}
		memset(mark, false, sizeof(mark));
		int S = func(1, N);
		printf("%d\n", S);
	}
    return 0;
}
