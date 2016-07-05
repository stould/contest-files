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

const Int MOD = 1000000007LL;

int N;
string S, T = "ACGT";

Int modPow(Int a, Int n, Int mod) {
	Int res = 1LL;
	while (n) {
		if (n&1)
			res=(res*a)%mod;
		a=(a*1ll*a)%mod;
		n>>=1;
	}
	return res;
}


int main(void) {
	cin >> N >> S;

	map<char, int> seen;
	
	for (int i = 0; i < N; i++) {
		seen[S[i]] += 1;
	}

	int best = 0, s = 0;
	
	for (int i = 0; i < 4; i++) {
		if (seen[T[i]] > best) {
			best = seen[T[i]];
			s = 1;
		} else if (seen[T[i]] == best) {
			s += 1;
		}
	}
	
	Int ans = modPow(s, N, MOD);
	
	cout << ans << "\n";
	
    return 0;
}
