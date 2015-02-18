#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <set>
#include <climits>


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

int C, N;
int P[25];

int main(void) {
	scanf("%d%d", &C, &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}

	int ans = 0;

	for (int i = 0; i < (1 << N); i++) {
		int curr = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				curr += P[j];
			}
		}
		if (curr < C) ans = max(ans, curr);
	}
	printf("%d\n", ans);
    return 0;
}

