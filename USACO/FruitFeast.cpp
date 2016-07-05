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

const int MAXN = 100005;
const int INF = INT_MAX / 3;

int N, A, B;
int dp[MAXN][2];

int func(int f, int used) {
	if (f > N) {
		return 0;
	} else if (f + A > N && f + B > N && used) {
		return f;
	} else {
		int& ans = dp[f][used];

		if (ans == -1) {
			ans = 0;

			chmax(ans, func(f + A, used));
			chmax(ans, func(f + B, used));

			if (!used) {
				chmax(ans, func(f / 2, 1));
			}			
		}
		
		return ans;
	}
}

int main(void) {
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	
	cin >> N >> A >> B;

	memset(dp, -1, sizeof(dp));

	cout << func(0, 0) <<"\n";
	
	return 0;
}
