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

const int MAXN = 1000005;
int N;
int P[MAXN], dp[MAXN];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	int ans = 0;
	priority_queue<pair<int, int> > pq;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		dp[i] = P[i];

		if (i - 1 >= 0) {
			chmax(dp[i], dp[i - 1]);
		}
		if (i - 2 >= 0) {
			chmax(dp[i], dp[i - 2]);
		}
		if (i - 3 >= 0) {
			chmax(dp[i], dp[i - 3] + P[i]);
		}
		
		chmax(ans, dp[i]);
	}

	cout << ans << endl;
	return 0;
}
