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

int N;
int P[100005], cnt[100005];
Int dp[100005];

Int func(int id) {
	if (id >= N) {
		return 0;
	} else {
		Int& ans = dp[id];

		if (ans == -1) {
			chmax(ans, (Int) cnt[P[id]] * P[id] + ((id + 1 < N && P[id] != P[id + 1] - 1) ? func(id + 1) : func(id + 2)));
			chmax(ans, func(id + 1));	
		}

		return ans;
	}
}

int main(void) {
	cin >> N;
	
	set<int> st;

	for (int i = 0; i < N; i++) {
		int p = in();
		st.insert(p);
		cnt[p] += 1;
	}
	N = 0;

	for (auto& i: st) {
		P[N++] = i;
	}
	
	memset(dp, -1LL, sizeof(dp));

	cout << func(0) << "\n";
	
    return 0;
}
