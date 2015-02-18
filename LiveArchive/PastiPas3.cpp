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
typedef unsigned long long uInt;

const int MAXN = 50050;

const uInt MOD = 1111111111111111111ULL;
const uInt BASE = 31ULL;

int T, N;
char S[MAXN];
uInt hA[MAXN], pA[MAXN], invA[MAXN];

int main(void) {
	scanf("%d", &T);

	pA[0] = 1LL;
	
	for (int i = 1; i < MAXN; i++) {
		if (i > 0) {
			pA[i] = (pA[i - 1] * BASE) % MOD;
		}		
	}

	for (int t = 1; t <= T; t++) {
		scanf("%s", S);
		N = strlen(S);

		int ans = 0;	   
	
		int i = 0;
		int j = N - 1;
		
		uInt ha = 0ULL;
		uInt hb = 0ULL;

		int len = 0;

		for ( ; i <= j; ) {			
			ha = (((ha * BASE) % MOD) + S[i]) % MOD;
			hb = (((S[j] * pA[len]) % MOD) + hb) % MOD;

			len += 1;

			if (i < j && ha == hb) {
				ans += 2;
				ha = hb = 0ULL;
				len = 0;
			}

			i += 1;
			j -= 1;
		}

		if (len != 0) ans += 1;

		printf("Case #%d: %d\n", t, ans);
	}
    return 0;
}
