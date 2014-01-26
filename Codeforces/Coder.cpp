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

int N;
char C[MAXN][MAXN];

int main(void) {
	N = in();

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					C[i][j] = 'C';
					ans += 1;
				} else {
					C[i][j] = '.';
				}
			} else {
				if (j % 2 == 0) {
					C[i][j] = '.';
				} else {
					C[i][j] = 'C';
					ans += 1;
				}
			}
		}
	}

	printf("%d\n", ans);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			putchar(C[i][j]);
		}
		puts("");
	}


    return 0;
}
