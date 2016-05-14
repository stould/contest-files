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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int T;
Int N, K;

Int modPow(Int n, Int k, Int MOD) {
	Int ans = 1;

	while (k > 0) {
		if (k % 2 == 1) {			
			ans = (ans * n) % MOD;
			ans = ((ans % MOD) + MOD) % MOD;
		}
		n = (n * n) % MOD;
		n = ((n % MOD) + MOD) % MOD;
		k /= 2;
	}
	
	return ans;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		
		Int trail = modPow(N, K, 1000);
		double lg = K * log10(N);
		double de = lg - floor(lg);

		printf("%d...%03lld\n", (int) (100 * pow(10, de)), trail);
	}
	return 0;
}
