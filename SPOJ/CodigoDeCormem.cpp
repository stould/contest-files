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

const int MAXN = 1148576;

int T, N;
int P[MAXN], sum[MAXN];

int main(void) {
	T = in();

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		sum[0] = 0;

		for (int i = 1; i <= N; i++) {
			P[i] = in();
			
			sum[i] = sum[i - 1] + P[i];			
		}

		int ans = 0;

		for (int i = 1; i <= N; i++) {
			int l = i + 1, h = N, m;
			int done = -1;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				int curr = sum[m] - sum[i - 1];

				if (curr == 42) {
					done = m;
					break;
				} else if (curr > 42) {
					h = m - 1;
				} else {
					l = m + 1;
				}				
			}
			if (done != -1) {
				ans += 1;
				i = done;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
