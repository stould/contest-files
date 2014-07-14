


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

const int MAXN = 1000006;

int N;
pair<int, int> P[MAXN];

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i].first, &P[i].second);
		}
		sort(P, P + N);

		int ans = -1, ans_id = 0;

		for (int i = 0; i < N; i++) {
			int us = 0;

			int l = i, h = N - 1, m;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				if (P[i].first + P[i].second >= P[m].first) {
					chmax(us, m - i);
					l = m + 1;
				} else {
					h = m - 1;
				}
			}

			if (us > ans) {
				ans = us;
				ans_id = P[i].first;
			}
		}
		printf("%d %d\n", ans_id, ans);
	}
	
    return 0;
}
