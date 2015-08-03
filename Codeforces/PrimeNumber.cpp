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

const int MAXN = 100005;
const int MOD = 1000000007LL;

int N, X;
int P[MAXN];

Int modpow(Int a, Int n) {
	Int res(1);
	while (n) {
		if (n&1) {
			res=(res*a)%MOD;
		}
		a=(a*1ll*a)%MOD;
		n>>=1;
	}
	return res % MOD;
}


int main(void) {
	cin >> N >> X;

	Int denom_exp = 0;
	Int numer_value = 0LL;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];

		denom_exp += P[i];
	}

	for (int i = 0; i < N; i++) {
		numer_value += modpow(X, denom_exp - P[i]);
		numer_value %= MOD;
	}
	
	Int denom_value = modpow(X, denom_exp);
	Int val_gcd = gcd(numer_value, denom_value);
	
	//cout << numer_value << " " << denom_value << endl;
	cout << gcd(1, gcd(3, 5)) << endl;
	if (val_gcd == 1) {
		cout << min(numer_value, denom_value) << "\n";
	} else {		
		cout << val_gcd << "\n";
	}
	
	return 0;
}
