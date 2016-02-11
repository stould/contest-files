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

int T, N;
uInt A, B;
string S;
uInt dp[30][30][5][5][12];
bool seen[30][30][5][5][12];

uInt func(int pos, int rev_pos, int pref, int rev_pref, int seen_non_zero, int last) {
	if (pos == N) {
		return 1;
	} else {
		uInt& ans = dp[pos][rev_pref][pref][rev_pref][last];

		if (!seen[pos][rev_pos][pref][rev_pref][last]) {
			seen[pos][rev_pos][pref][rev_pref][last] = true;

			ans = 0;

			for (char i = '0'; i <= '9'; i++) {
				if (pref && i > S[pos]) {
					continue;
				}
				if (rev_pos > 0 && rev_pref && i > S[rev_pos]) {
					continue;
				}

				ans += func(pos + 1, max(0, rev_pos - 1), pref && i == S[pos], rev_pref && i == S[rev_pos], seen_non_zero or i > '0', i - '0');
				
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> A >> B;

		memset(seen, false, sizeof(seen));

		S = " " + to_string(B);
		N = (int) S.size();

		uInt ans = 0;

		int rev_pos = N - 1;

		while (S[rev_pos] == '0' && rev_pos >= 1) {
			rev_pos -= 1;
		}
		ans += func(1, rev_pos, 1, 1, 0, 11) - 1;

		
		cout << ans << endl;
	}
	return 0;
}
