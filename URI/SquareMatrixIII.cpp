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

int N;
int M[16][16];

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		int digit = 0;

		for (int i = 0; i < N; i++) {
			int b = (int) pow(2.0, (double) i);
			for (int j = 0; j < N; j++) {
				M[i][j] = b;
				chmax(digit, (int) (1 + log10((double)b)));
				b *= 2;
			}
		}
		for (int i = 0; i < N; i++) {
			int b = (int) pow(2.0, (double) i);
			for (int j = 0; j < N; j++) {
				if (j == 0) printf("%*", digit);
				printf("%*d", digit, M[i][j]);
				if (j != N - 1) printf(" ");
			}
			printf("\n");		
		}
		printf("\n");
	}
    return 0;
}
