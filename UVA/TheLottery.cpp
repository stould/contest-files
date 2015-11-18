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

const int MAXN = 16;

Int N, M;
Int P[MAXN];

int main(void) {
	while (cin >> N >> M) {
		Int ans = 0;

		for (int i = 0; i < M; i++) {
			cin >> P[i];
		}

		for (int i = 1; i < (1 << M); i++) {
			if (__builtin_popcount(i) == 0) {
				continue;
			}

			Int val = 1;			

			for (int j = 0; j < M; j++) {
				if (i & (1 << j)) {
					val = lcm(val, P[j]);					
				}
			}
			if (__builtin_popcount(i) % 2 == 1) {
				ans += N / val;
			} else {
				ans -= N / val;
			}
		}

		cout << N - ans << "\n";
	}
	
	return 0;
}
