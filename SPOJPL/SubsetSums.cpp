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

const int MAXN = 18;

int N, AL, BL;
Int A, B;
Int SA[(1 << MAXN)];
Int SB[(1 << MAXN)];
int AR[MAXN], BR[MAXN];

int main(void) {
	for ( ; scanf("%d%lld%lld", &N, &A, &B) == 3; ) {
		AL = N / 2;
		BL = N - AL;

		int SALen = (1 << AL);
		int SBLen = (1 << BL);

		for (int i = 0; i < AL; i++) {
			scanf("%d", &AR[i]);
		}
		for (int i = 0; i < BL; i++) {
			scanf("%d", &BR[i]);
		}

		for (int i = 0; i < SALen; i++) {
			for (int j = 0; j < AL; j++) {
				if (i & (1 << j)) {
					SA[i] += AR[j];
				}
			}
		}
		for (int i = 0; i < SBLen; i++) {
			for (int j = 0; j < BL; j++) {
				if (i & (1 << j)) {
					SB[i] += BR[j];
				}
			}
		}

		sort(SA, SA + SALen);
		sort(SB, SB + SBLen);

		Int ans = 0LL;
		
		for (int i = 0; i < SALen; i++) {
			int pos_l = (lower_bound(SB, SB + SBLen, A - SA[i]) - SB);			
			int pos_r = (upper_bound(SB, SB + SBLen, B - SA[i]) - SB) - 1;		 

			if (pos_l <= pos_r) {			
				ans += pos_r - (Int) pos_l + 1;
			}			
		}

		printf("%lld\n", ans);
	}
    return 0;
}
