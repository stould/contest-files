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

int N;
int dp[50][5];

int func(int pos, int sit) {
	if (pos == N - 1 && sit == 3) {
		return 1;
	} else if (pos == N && sit == 0) {
		return 1;
	} else if (pos > N) {
		return 0;
	} else {
		int& ans = dp[pos][sit];
		
		if (ans == -1) {
			ans = 0;
			
			if (sit == 0) {
				ans += func(pos + 1, 1);
				ans += func(pos + 1, 2);
				ans += func(pos + 1, 3);				
			} else if (sit == 3) {
				ans += func(pos + 2, 1);
				ans += func(pos + 2, 2);				
				ans += func(pos + 2, 3);
			} else {
				ans += func(pos + 1, 0);
				ans += func(pos + 2, 1);
			}
		}

		return ans;
	}
}

int main(void) {
	while (cin >> N && N != -1) {
		memset(dp, -1, sizeof(dp));
		cout << func(0, 0) << endl;
	}
	return 0;
}
