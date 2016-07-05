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

const int INF = INT_MAX / 6;

int N, M, K;
Int F[20];
Int S[20][20];
Int dp[18][(1 << 18)];

Int func(int id, int mask) {
	if (__builtin_popcount(mask) == M) {
		return 0;
	} else {
		Int& ans = dp[id][mask];

		if (ans == -1) {
			ans = -INF;

			for (int i = 0; i < N; i++) {
				if (!(mask & (1 << i))) {
					chmax(ans, S[id][i] + F[i] + func(i, mask | (1 << i)));
				}
			}
		}
		
		return ans;
	}
}
int main(void) {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> F[i];
	}
	
	Int A, B, C;
	for (int i = 0; i < K; i++) {
		cin >> A >> B >> C;
		
		A -= 1;
		B -= 1;
		
		S[A][B] = C;
	}

	memset(dp, -1LL, sizeof(dp));

	Int ans = 0;

	for (int i = 0; i < N; i++) {
		chmax(ans, F[i] + func(i, 1 << i));
	}

	cout << ans << "\n";
	return 0;
}
