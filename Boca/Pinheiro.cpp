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

const int MAXN = 10005;

int N;
int P[MAXN];

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int l = i == 0 ? N - 1 : i - 1;
			int r = i == N - 1 ? 0 : i + 1;

			if (P[i] > P[l] && P[i] > P[r]) {
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
