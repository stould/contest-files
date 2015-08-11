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
Int P[MAXN];

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
	Int ans = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		denom_exp += P[i];
	}

	vector<Int> pw;

	for (int i = 0; i < N; i++) {
		pw.push_back(denom_exp - P[i]);
	}

	sort(pw.rbegin(), pw.rend());

	while (true) {
		Int smallest_power = pw.back();
		int cnt = 0;

		while (!pw.empty() && pw.back() == smallest_power) {
			cnt += 1;
			pw.pop_back();
		}

		ans = smallest_power;
		
		if (cnt % X != 0) break;
		
		cnt /= X;
		
		for (int i = 0; i < cnt; i++) {
			pw.push_back(smallest_power + 1);
		}
	}

	cout << modpow(X, min(ans, denom_exp)) << "\n";
	
	return 0;
}
