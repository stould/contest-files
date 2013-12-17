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

int N, K;

int tb[110][110];

int main(void) {
	N = in();
	K = in();

	int i;
	int j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == j) {
				printf("%d ", K - (N - 1));
			} else {
				printf("%d ", 1);
			}
		}
		printf("\n");
	}

    return 0;
}