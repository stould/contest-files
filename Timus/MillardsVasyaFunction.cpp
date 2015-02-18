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

int S;
int dp[10][90];

int func(int pos, int sum, int num) {
	if (pos == 9) {
		return sum == S && num <= 1e9;
	} else {
		int& ans = dp[pos][sum];
		
		if (ans == -1) {
			ans = 0;

			for (int i = 0; i <= 9; i++) {
				ans += func(pos + 1, sum + i, num * 10 + i);
			}
		}

		return ans;
	}
}

int main(void) {
	scanf("%d", &S);
	if (S == 1) {
		printf("10");
	} else {
		memset(dp, -1, sizeof(dp));
		printf("%d\n", func(0, 0, 0));
	}
    return 0;
}
