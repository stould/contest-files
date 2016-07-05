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

typedef unsigned long long Int;
typedef unsigned uint;

const Int MAX_VAL = ULLONG_MAX - 1;

Int N;
int len;
string as_s;
Int dp[70][12][2];

Int func(int pos, int last, int pref) {
	if (pos == len) {
		return 1LL;
	} else {
		Int& ans = dp[pos][last][pref];

		if (ans == -1ULL) {
			ans = 0;

			int now_val = as_s[pos] - '0';
			
			for (int i = 0; i < 10; i++) {
				if (i == 4 || (i == 3 && last == 1)) continue;
				if (pref && i > now_val) continue;

				ans += func(pos + 1, i, pref && i == now_val);
			}
		}
		
		return ans;
	}
}

int main(void) {
	while (cin >> N) {		
		Int l = 1, h = MAX_VAL, m;
		
		while (l <= h) {
			m = l + (h - l) / 2;

			memset(dp, -1, sizeof(dp));

			as_s = to_string(m);
			len = (int) as_s.size();

			Int least = func(0, 10, 1) - 1;
			
			//cout << N << " " << m << " " << least << endl;
			
			if (least >= N) {
				h = m - 1;
			} else {
				l = m + 1;				
			}
		}
		cout << l << endl;
	}
		

	/*for (int i = 1; i <= 30; i++) {
		as_s = to_string(i);
		len = (int) as_s.size();
		
		memset(dp, -1, sizeof(dp));
		
		cout << i << " " << func(0, 10, 1) - 1 << endl;
	}
	*/
	return 0;
}

	
