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

int X[5], Y[5], P[5];

int func(int r, int c) {
	int lr = 0, lc = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			
		}
	}
}

int main(void) {
	for (int i = 0; i < 4; i++) {
		P[i] = i;
		scanf("%d%d"< &X[i], &Y[i]);
	}
	
	do {
		for (int i = 1; i <= 4; i++) { //r
			for (int j = 1; j <= 4; j++) { //c
				if (i + j == 4) {
					
				}
			}
		}
	} while (next_permutation(P, P + 5));

    return 0;
}
