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

int T;
int sy, sm, sd, ey, em, ed;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(int y) {
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main(void) {
	scanf("%d", &T);
	for ( ; T--; ) {
		scanf("%d-%d-%d %d-%d-%d", &ey, &em, &ed, &sy, &sm, &sd);

		if (ey < sy || (ey == sy && em < sm || (ey == sy && em == sm && ed < sd))) {
			swap(ey, sy);
			swap(em, sm);
			swap(ed, sd);
		}
		
		int ans = 0;

		for (int i = sm; i <= 12; i++) {
			if (i == 2 && leap(sy)) {
				for (int j = (i == sm ? sd : 1); j <= 29; j++) {
					if (sy == ey && i == em && j == ed) {
						goto ed1;
					}
					ans += 1;
				}
			} else {
				for (int j = (i == sm ? sd : 1); j <= days[i]; j++) {
					if (sy == ey && i == em && j == ed) {
						goto ed1;
					}
					ans += 1;
				}
			}
		}
	ed1:;
		if (sy != ey) {
			for (int i = em; i >= 1; i--) {
				if (i == 2 && leap(ey)) {
					for (int j = (i == em) ? ed - 1: 29; j >= 1; j--) {
						if (sy == ey && i == sm && j == sd) {
							goto ed2;
						}
						ans += 1;
					}
				} else {
					for (int j = (i == em) ? ed - 1 : days[i]; j >= 1; j--) {
						if (sy == ey && i == sm && j == sd) {
							goto ed2;
						}
						ans += 1;
					}
				}
			}
		}
	ed2:;
				 
		for (int i = sy + 1; i < ey; i++) {
			if (leap(i)) {
				ans += 366;
			} else {
				ans += 365;
			}
		}		
		printf("%d\n", ans);
	}
    return 0;
}
