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
typedef unsigned uint;

const Int MOD = 1000000007LL;
int T, N;

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		Int ans = 1;
		
		for (int i = 1; i <= N; i++) {
			ans = ((ans % MOD) * i) % MOD;
		}
		ans -= 1;

		ans = ((ans % MOD) + MOD) % MOD;

		cout << ans << "\n";
	}
	return 0;
}
