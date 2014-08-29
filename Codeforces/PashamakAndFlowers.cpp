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

const int MAXN = 200005;

int N, P[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	
	sort(P, P + N);

	int ans = P[N-1] - P[0];
	Int cnt = 0LL;

	if (ans == 0) {
		cnt = (N * (Int) (N + 1)) / 2 - N;
	} else {
		int p0 = 0, p1 = 0;

		for (int i = 0; i < N; i++) {
			if (P[i] != P[0]) break;
			p0 += 1;
		}
		for (int i = 0; i < N; i++) {
			if (P[N - i - 1] != P[N - 1]) break;
			p1 += 1;
		}
		cnt = p0 * (Int) p1;
	}

	printf("%d %lld\n",  ans, cnt);
	
    return 0;
}
