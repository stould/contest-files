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
	int l, m, r;

	interval() {
	}
	
	data(int l, int r): l(l), r(r) {
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
 		return (l + (l + r) / 2) < (it.l + (it.l + it.r) / 2);
	}
};

interval data[MAXN];

int main(void) {
	T = in();

	for (int t = 1; t <= T; t++) {
		N = in();
		M = in();

		for (int i = 0; i < N; i++) {
			int a = in();
			int b = in();
			
			data[i] = interval(a, b);
		}

		sort(data, data + N);

		for (int i = 0; i < M; i++) {
			int x = in();

			int l = 0, h = N - 1, m;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				if (data[m].l > x) {
					l = m + 1;
				} else if (data[m].r < x) {
					h = m - 1;
				}
			}
		}
	}
    return 0;
}
