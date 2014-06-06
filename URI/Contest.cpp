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

const int MAXN = 110;

int N, M;
int user[MAXN], solved[MAXN];

int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		int ans = 0;
		bool a = true, b = true, c = true, d = true;

		for (int i = 0; i < MAXN; i++) {
			user[i] = solved[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int b;
				scanf("%d", &b);
				if (b == 1) {
					user[i] += 1;
					solved[j] += 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (user[i] == M) {
				a = false;
			}
			if (user[i] == 0) {
				d = false;
			}			
		}
		for (int i = 0; i < M; i++) {
			if (solved[i] == 0) {
				b = false;
			}
			if (solved[i] == N) {
				c = false;
			}		
		}
		if (a) ans += 1;
		if (b) ans += 1;
		if (c) ans += 1;
		if (d) ans += 1;
		printf("%d\n", ans);
	}
    return 0;
}
