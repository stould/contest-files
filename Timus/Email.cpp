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

const int MAXN = 2002;
const int MOD = 1000000007;

string A, B;
int N, M;
Int dp[MAXN][MAXN];

Int func(int i, int j) {
	if (i >= N or j >= M) {
		return 1;
	} else {
		Int& ans = dp[i][j];

		if (ans == -1) {
			ans = 0;

			if (A[i] == B[j]) {
				ans += func(i + 1, j + 1);
			} else {
				ans += func(i + 1, j);
				ans += func(i, j + 1);
			}
		}

		ans %= MOD;
		
		return ans % MOD;
	}
}

int main(void) {
	cin >> A >> B;

	N = (int) A.size();
	M = (int) B.size();

	memset(dp, -1, sizeof(dp));
	
	cout << func(0, 0) << endl;
	
	return 0;
}
