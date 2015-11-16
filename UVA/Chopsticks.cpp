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

const int MAXN = 5001;
const Int INF = 100101101001010010LL;

int T, K, N;
int P[MAXN];
Int dp[MAXN][1050];

Int func(int pos, int match) {
	if (match == 0) {
		return 0;
	} else if (pos >= N - 1 or match * 3 > N - pos) {
		return INF;
	} else {
		Int& ans = dp[pos][match];
		
		if (ans == -1) {
			ans = func(pos + 1, match);
			ans = min(ans, (P[pos] - P[pos + 1]) * (Int) (P[pos] - P[pos + 1]) + func(pos + 2, match - 1));			
		}
		
		return ans;	
	}		
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> K >> N;

		K += 8;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		sort(P, P + N);

		memset(dp, -1, sizeof(dp));

		Int ans = func(0, K);

		cout << ans << endl;
	}
	return 0;
}
