#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

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
int X[22];

int main(void) {
	N = in();

	for (int i = 0; i < N; i++) {
		X[i] = in();
	}

	int ans = INT_MAX/3;

	for (int i = 0; i < (1 << N); i++) {
		int curr = 0;

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				curr += X[j];
			} else {
				curr -= X[j];
			}
		}
		chmin(ans, abs(curr));
	}

	printf("%d\n", ans);
    return 0;
}
