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

const int MAXN = 101000;
const int INF = 100;

int T, N;
string S[2];
int dp[MAXN][2][2];

int func(int pos, int cu, int cl) {
	if (pos == N - 1) {
		if (cu || cl) return 0;
	} else {
		int& ans = dp[pos][cu][cl];

		if (ans == -1) {
			ans = INF;

			if (S[pos] == '.') {			
				
			}			
		}

		return ans;
	}
	
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		cin >> S[0] >> S[1];

		memset(dp, -1, sizeof(dp));
		

	}
	return 0;
}
