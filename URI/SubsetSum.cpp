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

const int MAXN = 10004;

int T, N;
int P[MAXN];

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);			
		}

		sort(P, P + N);

		if (P[0] != 1) {
			printf("1\n");
		} else {
			Int until = 0;

			for (int i = 0; i < N; i++) {
				if (P[i] > until + 1) {
					break;
				}
				until += P[i];
			}
			printf("%lld\n", until + 1);
		}
	}
    return 0;
}
