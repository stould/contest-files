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

const int MAXN = 1010;

int N;
int P[MAXN];

int func(int x) {
	int l = 0, h = N, m;
	int ans = 0;

	for ( ; l <= h; ) {
		m = (l + h) / 2;
		
		if (P[m] >= x) {
			chmax(ans, N - m);
			h = m - 1;
		} else {
			l = m + 1;
		}
	}	   

	return ans;
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		map<int, int> mp;
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		sort(P, P + N);

		int l = 0, h = P[N-1], m;
		int ans = -1;

		for ( ; l <= h; ) {
			m = (l + h) / 2;

			if (func(m) >= m) {
				chmax(ans, m);
				l = m + 1;
			} else {
				h = m - 1;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
