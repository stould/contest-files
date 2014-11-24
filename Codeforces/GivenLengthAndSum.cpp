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

const int MAXN = 105;

int M, S;
int dp[MAXN][11][1010];
string L, R;

//O(10^M)
int funcL(int pos, int digit, int sum) {
	if (sum < 0) {
		return 0;
	} else if (pos == M) {
		return sum == 0 ? 1 : 0;
	} else {
		int& ans = dp[pos][digit][sum];
		
		if (ans == -1) {
			ans = 0;

			for (int i = 0; i < 10; i++) {
				if (pos == 0 && i == 0 && M != 1) continue;
				
				int curr = funcL(pos + 1, i, sum - i);
				
				if (curr == 1) {
					ans = 1;
					break;
				}
			}
		}

		return ans;
	}	
}

void recL(int pos, int digit, int sum) {
	if (sum < 0) {
		return;
	} else if (pos == M) {
		return;
	} else {
		for (int i = 0; i < 10; i++) {
			if (pos == 0 && i == 0 && M != 1) continue;

			if (funcL(pos + 1, i, sum - i) == 1) {
				L += char('0' + i);
				recL(pos + 1, i, sum - i);
				break;
			}
		}		
	}
}

int funcR(int pos, int digit, int sum) {
	if (sum < 0) {
		return 0;
	} else if (pos == M + 1) {
		return sum == 0 ? 1 : 0;
	} else {
		int& ans = dp[pos][digit][sum];
		
		if (ans == -1) {
			ans = 0;

			for (int i = 9; i >= 0; i--) {
				if (pos == 0 && i == 0 && M != 1) continue;
				
				int curr = funcR(pos + 1, i, sum - i);
				
				if (curr == 1) {
					ans = 1;
					break;
				}
			}
		}

		return ans;
	}	
}

void recR(int pos, int digit, int sum) {
	if (sum < 0) {
		return;
	} else if (pos == M) {
		return;
	} else {
		for (int i = 9; i >= 0; i--) {
			if (pos == 0 && i == 0 && M != 1) continue;

			if (funcR(pos + 1, i, sum - i) == 1) {
				R += char('0' + i);
				recR(pos + 1, i, sum - i);
				break;
			}
		}		
	}
}

int main(void) {
	cin >> M >> S;

	memset(dp, -1, sizeof(dp));
	funcL(0, 0, S);
	recL(0, 0, S);

	memset(dp, -1, sizeof(dp));
	funcR(0, 0, S);
	recR(0, 0, S);

	if (L == "") {
		L = R = "-1";
	}	

	cout << L << " " << R << "\n";

    return 0;
}
