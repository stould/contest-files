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

char S[MAXN];
bool dp[MAXN][MAXN];

int main(void) {
	scanf("%s", S);
	N = strlen(S);

	int ans = 1, pos = 0;

	for (int i = 0; i < N; i++) {
		dp[i][i] = true;
		if (i + 1 < N && S[i] == S[i + 1]) {
			dp[i][i + 1] = true;
			if (ans < 2) {
				ans = 2;
				pos = i;
			}
		}
	}
	
	for (int len = 2; len < N; len++) {
		for (int i = 0; i < N - len; i++) {
			if (S[i] == S[i + len] && dp[i + 1][i + len - 1]) {
				dp[i][i + len] = true;
				if (len + 1 > ans || (len + 1 == ans && i < pos)) {
					ans = len + 1;
					pos = i;
				}
			}
		}
	}
	for (int i = 0; i < ans; i++) {
		putchar(S[pos + i]);
	}
	putchar('\n');
    return 0;
}
