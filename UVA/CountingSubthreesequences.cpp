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

const int MAXN = 1000005;

string S, P;
int N;

int dp[MAXN][4];

int func(int id, int sum) {
	if (sum == 0) {
		return 0;
	}
	if (id >= N) {
		return 0;
	} else {
		int& ans = dp[id][sum];

		if (ans == -1) {
			ans = 0;
			ans = func(id + 1, 1);

			int s = 0;

			for (int i = id; i < N; i++) {
				s = (s + (P[i] - '0')) % 3;
				if (s == 0) {
					ans += 1 + func(i + 1, s);						
				}
			}
		}

		return ans;
	}
}

int main(void) {
	for ( ; cin >> S; ) {
		int ans = 0;
		P = "";
		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] >= '0' && S[i] <= '9') {
				P += S[i];
			} else {
				if (P == "") continue;
				memset(dp, -1, sizeof(dp));
				N = P.size();
				ans += func(0, 1);
				P = "";
			}
		}
		if (P != "") {
			memset(dp, -1, sizeof(dp));
			N = (int) P.size();
			ans += func(0, 1);
		}
		
		cout << ans << "\n";
	}
    return 0;
}
