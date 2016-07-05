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

const int INF = INT_MAX / 3;

int T, N;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		
		vector<int> ev, od;
		int c;
		
		for (int i = 0; i < N; i++) {
			cin >> c;

			if (c % 2 == 0) {
				ev.push_back(c);
			} else {
				od.push_back(c);
			}
		}

		sort(ev.begin(), ev.end());
		sort(od.begin(), od.end());

		Int ans = 0LL;

		for (int i = 0; i < (int) ev.size(); i++) {
			int l = i, h = (int) ev.size() - 1, m = i;
			int small = INF;
			
			while (l <= h) {
				m = (l + h) / 2;
				
				if (ev[m] == ev[i]) {
					l = m + 1;
				} else {
					small = min(small, m);
					h = m - 1;
				}
			}
			if (small != INF) {
				ans += (int) ev.size() - small;
			}
		}

		for (int i = 0; i < (int) od.size(); i++) {
			int l = i, h = (int) od.size() - 1, m = i;
			int small = INF;
			
			while (l <= h) {
				m = (l + h) / 2;

				if (od[m] == od[i]) {
					l = m + 1;
				} else {
					small = min(small, m);
					h = m - 1;
				}
			}
			if (small != INF) {
				ans += (int) od.size() - small;
			}
		}
				
		cout << ans << "\n";
	}
	return 0;
}
