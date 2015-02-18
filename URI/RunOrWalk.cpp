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

int T, S, C, R;
int P[MAXN];

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d%d%d", &S, &C, &R);
		for (int i = 0; i < S; i++) {
			scanf("%d", &P[i]);
		}
		
		sort(P, P + S);
		
		double ans = 0.0;
		
		for (int i = 0; i < C; i++) {
			double now = now = 1.0 / (P[i] + R);
			ans += now;
		}
		
		for (int i = C; i < S; i++) {
			double now = 1.0 / (P[i]);
			ans += now;
		}
		printf("%.2lf\n", ans);
	}
    return 0;
}
