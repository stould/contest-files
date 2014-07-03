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

const int INF = 1010001010;

int T, A, B;
int dp[100005];

int rev(int x) {
	int ans = 0;
	
	while (x > 0) {
		ans = ans * 10 + (x % 10);
		x /= 10;
	}
	return ans;
}

int func(int x) {
	queue<int> q;
	memset(dp, 63, sizeof(dp));
	dp[x] = 0;
	q.push(x);
	for ( ; !q.empty(); ) {
		int p = q.front(); q.pop();
		if (p == B) return dp[p];
		int pp = rev(p), vv = p + 1;
		
		if (dp[pp] > dp[p] + 1 && (pp > 0 && pp < 10000)) {
			dp[pp] = dp[p] + 1;
			q.push(pp);
		}
		if (dp[vv] > dp[p] + 1 && (vv > 0 && vv < 10000)) {
			dp[vv] = dp[p] + 1;
			q.push(vv);
		}
	}
	return -1;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> T;	

	for ( ; T--; ) {
		cin >> A >> B;
		cout << func(A) << "\n";
	}
    return 0;
}
