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

const int MAXN = 200002;

int N, K, X;
Int P[MAXN];
Int dp[MAXN][20];

Int func(int pos, int used) {
	if (pos == N) {
		return 0;
	} else {
		Int& ans = dp[pos][used];

		if (ans == -1) {
			ans = P[pos] | func(pos + 1, used);

			Int curr = P[pos];
			
			for (int i = 1; i <= used; i++) {
				curr *= X;
				chmax(ans, curr | func(pos + 1, used - i));
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N >> K >> X;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	memset(dp, -1, sizeof(dp));
	
	cout << func(0, K) << "\n";	
	
	return 0;
}
