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

const int MAXN = 20;

int C, V;
Int bin[MAXN][MAXN];

Int fat(int x) {
	Int ans = 1LL;

	for (int i = 1; i <= x; i++) {
		ans *= i;
	}
	
	return ans;
}

int main(void) {
	bin[0][0] = 1LL;
	
	for (int n = 1; n < MAXN; n++) {
		bin[n][0] = 1LL;
		bin[n][n] = 1LL;
		
		for (int k = 1; k < n; k++) {
			bin[n][k] = bin[n - 1][k] + bin[n - 1][k - 1];
		}
	}

	for ( ; scanf("%d%d", &C, &V) == 2 && !(C == -1 && V == -1); ) {
		Int A = (C + 1) * fat(C);
		Int B = (C + 1) * fat(C) * fat(V);
		Int D = fat(C) * bin[C + V][C];

		if (V == 0) {
			A = fat(C);
			B = fat(C);
		}
		
		printf("%lld %lld %lld\n", A, B, D);
	}
	
    return 0;
}
