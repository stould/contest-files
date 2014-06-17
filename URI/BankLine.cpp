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

const int MAXN = 100003;
const Int MOD = 1000000009LL;

int N;
Int P[MAXN];

int main(void) {
	P[3] = 1LL;

	for (int i = 4; i <= 100000; i++) {		
		P[i] = (P[i - 1] * i) % MOD;
	}
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		printf("%lld\n", P[N]);
	}
    return 0;
}
