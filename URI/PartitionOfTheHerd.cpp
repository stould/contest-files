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

int N, P[MAXN];

//Outside interval [0, a) + (b, N - 1]
int funcO(int a, int b) {
	int L = a + (N - 1) - b;

	if (L == 1) return 0;
	int ans = 0, pos = 1;

	for (int i = 0; i < a; i++) {
		ans -= P[i] * (L - pos);
		ans += P[i] * (pos - 1);
		pos += 1;
	}
	for (int i = b + 1; i <= N - 1; i++) {
		ans -= P[i] * (L - pos);
		ans += P[i] * (pos - 1);
		pos += 1;
	}

	return ans;
}

//Inside interval [a, b]
int funcI(int a, int b) {
	int L = b - a + 1;

	if (L == 1) return 0;
	int ans = 0, pos = 1;

	for (int i = a; i <= b; i++) {
		ans -= P[i] * (L - pos);
		ans += P[i] * (pos - 1);
		pos += 1;
	}

	return ans;
}

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {				
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}

		sort(P, P + N);

		int ans = funcI(0, N - 1);
		int l = 0, r = N - 1;

		for (int i = 0; i < N; i++) {
			for (int j = i + (N / 2) - 1; j < N; j++) {
				int now = funcI(i, j) + funcO(i, j);
				if (now < ans) {
					ans = now;
					l = i;
					r = j;
				}
			}
		}

		printf("%d\n", ans);
	}
    return 0;
}
