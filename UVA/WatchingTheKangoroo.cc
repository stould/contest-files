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
const int MAXN = 100002;

int T, N, M;

struct interval {
	int l, r;

	interval() {
	}
	
	interval(int ll, int rr) {
		l = ll;
		r = rr;
	}

	int dist(int x) {
		if (x < l) {
		} else if (x > r) {
			return INF;
		} else {
			return min(x - l, r - x);
		}
	}
	bool operator<(const interval& it) const {
		return m < it.m;
	}
};

int main(void) {
	T = in();

	for (int t = 1; t <= T; t++) {
		N = in();
		M = in();

		vector<interval> data;

		for (int i = 0; i < N; i++) {
			int a = in();
			int b = in();

			if ((b - a + 1) % 2 == 0) {
				int m = (a + b) / 2;
				data.push_back(interval(a, m, m));
			} else {
				int m = (a + b) / 2;
				data.push_back(interval(a, n, m));
				data.push_back(interval(a, b, m + 1));				
				data.push_back(interval(a, b, m - 1));				
			}
		}

		N = (int) data.size();

		sort(data.begin(), data.end());

		for (int i = 0; i < M; i++) {
			int x = in();

			int ans = 0;
			int l = 0, h = N - 1, m;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				if (x >= data[m].l && x <= data[m].r) {
					ans = max(ans, data[m].dist(x));
				}

				if (data[m].m > x) {
					l = m + 1;
				} else  {
					h = m - 1;
				}
			}
			printf("%d\n", ans);
		}
	}
    return 0;
}
