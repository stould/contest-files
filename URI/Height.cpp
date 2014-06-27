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

int T, N, C[235], P;

int main(void) {
	scanf("%d", &T);
	for ( ; T--; ) {
		scanf("%d", &N);

		memset(C, 0, sizeof(C));

		for (int i = 0; i < N; i++) {
			scanf("%d", &P);
			C[P] += 1;
		}
		for (int i = 20; i <= 230; i++) {
			for (int j = 0; j < C[i]; j++) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
    return 0;
}
