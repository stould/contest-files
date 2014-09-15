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

const int MAXS = 2020;

int N;
char S[MAXS];
bool pal[MAXS][MAXS];
int dp[MAXS];

int func(int id) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id];

		if (ans == -1) {
			ans = 1010101;
			for (int i = N - 1; i >= id; i--) {
				if (pal[id][i]) {
					chmin(ans, 1 + func(i + 1));
				}
			}
		}

		return ans;
	}
}

int main(void) {
	int t = 1;
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		scanf("%s", S);

		memset(pal, false, sizeof(pal));
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < N; i++) {
			pal[i][i] = true;
			if (i + 1 < N && S[i] == S[i + 1]) {
				pal[i][i + 1] = true;
			}
		}
		for (int i = 3; i <= N; i++) {
			for (int j = 0; j < N - i + 1; j++) {
				int k = j + i - 1;
				
				if (S[j] == S[k] && pal[j + 1][k - 1]) {
					pal[j][k] = true;
				}
			}
		}
		printf("Teste %d\n%d\n\n", t++, func(0));
	}
    return 0;
}
