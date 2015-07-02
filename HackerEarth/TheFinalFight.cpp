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

const Int MOD = 1000000009LL;
const int MAXN = 200005;

int N;
Int fat[MAXN];

Int modpow(Int a, Int n, Int mod) {
	Int res = 1LL;
	while (n) {
		if (n&1) {
			res=(res*a)%mod;
		}
		a = (a*1ll*a)%mod;
		n >>= 1;
	}
	return res % MOD;
}


int main(void) {
	cin >> N;

	fat[1] = 1;
	
	for (int i = 2; i <= 2 * N; i++) {
		fat[i] = fat[i - 1] * (Int) i;
		fat[i] = ((fat[i] % MOD) + MOD) % MOD;
	}
	
	Int ans = fat[2 * N];
	Int p = ((fat[N] * fat[N + 1]) % MOD) % MOD;
	ans *= modpow(p, MOD - 2, MOD);
	
	ans = ((ans % MOD) + MOD) % MOD;
	
	cout << ans % MOD << "\n";
	
	return 0;
}
