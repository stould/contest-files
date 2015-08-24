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
typedef unsigned uint;

const int MAXN = 500005;
int N, M;
int dp[MAXN];

int func(int val) {
	if (val >= MAXN) return INT_MAX / 4;

	if (val == M) {
		return 0;
	} else {
		int& ans = dp[val];

	if (ans == -1) {
			ans = 100101000;
			if (val > M) {
				chmin(ans, 1 + func(val / 2));
				chmin(ans, 1 + func(val / 3));
				if (val - 7 >= 0) {
					chmin(ans, 1 + func(val - 7));
				}
			} else {
				chmin(ans, 1 + func(val * 2));
				chmin(ans, 1 + func(val * 3));
				chmin(ans, 1 + func(val + 7));
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N >> M;
	memset(dp, -1, sizeof(dp));
	cout << func(N) << "\n";
	return 0;
}
