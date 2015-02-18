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

Int P;
string S;

bool func(string K) {
	Int cost = 0LL;

	for (int i = 0; i < 5; i++) {
		int pos = K[i] - 'A' + 1;

		if (i % 2 == 0) {
			cost += (Int) pow(pos, i + 1);
		} else {
			cost -= (Int) pow(pos, i + 1);
		}
	}

	return cost == P;	
}

int main(void) {
	for ( ; cin >> P >> S && !(P == 0 && S == "END"); ) {
		int N = (int) S.size();
		string ans = "";

		for (int i = 0; i < (1 << N); i++) {
			if (__builtin_popcount(i) == 5) {
				string bf = "";
				for (int j = 0; j < N; j++) {
					if (i & (1 << j)) {
						bf += S[j];
					}
				}
				sort(bf.begin(), bf.end());

				do {
					if (func(bf) && bf > ans) {
						ans = bf;
					}
				} while (next_permutation(bf.begin(), bf.end()));
			}
		}
		if (ans == "") ans = "no solution";

		cout << ans << "\n";							
	}
    return 0;
}
