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

int N, T;
double P;
double dp[2020][2020];
bool seen[2020][2020];

double func(int cnt, int t) {
	if (t - 1 == T || cnt == N) {
		return cnt;
	} else {
		double& ans = dp[cnt][t];

		if (!seen[cnt][t]) {
			seen[cnt][t] = true;

			ans = 0.0;
			
			ans += P * func(cnt + 1, t + 1);
			ans += (1.0 - P) * func(cnt, t + 1);
		}
		return ans;
	}
}

int main(void) {
	cin >> N >> P >> T;
	
	cout << fixed << setprecision(6) << func(0, 1) << "\n";
	
    return 0;
}
