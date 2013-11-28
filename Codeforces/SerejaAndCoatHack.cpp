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

int N, D;
int M;

int a[110];

int main(void) {
	N = in();
	D = in();

	int i;

	for (i = 0; i < N; i++) {	
		a[i] = in();
	}

	M = in();

	int ans = 0;

	sort(a, a + N);

	for (i = 0; i < min(N, M); i++) {
		ans += a[i];
	}

	if (M > N) {
		ans -= D * (M - N);
	}

	printf("%d\n", ans);

    return 0;
}
