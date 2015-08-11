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

const Int MAX_V = 100000LL;

int N, K;
Int dp[50][5][2];
string S;

void conv(string& arg, Int val) {
	arg = "";

	if (val == 0) arg = "";
	
	while (val > 0) {
		arg = ((val % 2 == 0) ? '0' : '1') + arg;
		val /= 2;
	}
	while (N > (int) arg.size()) {
		arg = "0" + arg;
	}
}

Int func(int pos, int last, int pref) {
	if (pos == N) {
		return 1;
	} else {
		Int& ans = dp[pos][last][pref];

		if (ans == -1) {
			ans = func(pos + 1, 0, pref && S[pos] == '0');

			if (last != 1 && (S[pos] == '1' || !pref)) {
				ans += func(pos + 1, 1, pref && S[pos] == '1');
			}				
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N >> K;

	Int best_len = 0LL;

	for (int i = 0; i <= N; i++) {
		best_len |= (Int) (1LL << i);
	}
	
	Int l = 0, h = best_len, m;

	while (l <= h) {
		m = l + (h - l) / 2;

		memset(dp, -1, sizeof(dp));
		conv(S, m);
		
		Int curr = func(0, 0, 1);

		//cout << m << " " << S << " " << curr << "\n";
		
		if (curr >= K) {
			h = m - 1;
		} else {
			l = m + 1;
		}
	}
	conv(S, l);
	if (N < (int)S.size()) {
		cout << "-1\n";
	} else {
		cout << S << "\n";
	}
	return 0;

}
