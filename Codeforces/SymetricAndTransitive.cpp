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

const int MAXN = 5001;
const Int MOD = 1000000007LL;

Int N;
Int dp[MAXN];

int main(void) {		
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 1; i <= N; i++) {
		dp[i + 1] = ((i * (dp[i] % MOD) % MOD)) + (dp[i - 1] % MOD);

		dp[i + 1] = ((dp[i + 1] % MOD) + MOD) % MOD;
	}
	
	cout << dp[N+1] % MOD << "\n";
	
	return 0;
}
