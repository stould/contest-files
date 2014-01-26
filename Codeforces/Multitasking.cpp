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

int N, M, K;
int A[1010][110];

int main(void) {
	N = in();
	M = in(); 
	K = in();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = in();
		}
	}

	printf("%d\n", M * (M - 1) / 2);

	for (int i = 1; i <= M; i++) {
		for (int j = i + 1; j <= M; j++) {
			if (K == 0) {
				printf("%d %d\n", i, j);
			} else {
				printf("%d %d\n", j, i);
			}
		}
	}
    return 0;
}
