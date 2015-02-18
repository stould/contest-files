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

const int MAXN = 100005;

int T;
int N, M, P[MAXN];

bool func(int x) {
	int used = 1, last = P[0] + x;
	
	for (int i = 1; i < N; i++) {
		if (P[i] - x > last) {
			used += 1;
			last = P[i] + x;
		}
	}

	return used <= M;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> M >> N;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
			P[i] *= 10;
		}

		sort(P, P + N);
		
		int ans = INT_MAX;
		int l = 0, h = P[N-1] + 10;
		
		for ( ; l <= h; ) {
			int m = (l + h) / 2;
			
			if (func(m)) {
				chmin(ans, m);
				h = m - 1;
			} else {
				l = m + 1;
			}
		}

		printf("%d.%d\n", ans / 10, ans % 10);
	}
    return 0;
}
