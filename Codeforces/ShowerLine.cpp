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

int G[7][7];

int main(void) {
	int p[5];

	for (int i = 0; i < 5; i++) {
		p[i] = i;
		for (int j = 0; j < 5; j++) {
			scanf("%d", &G[i][j]);
		}
	}
	int ans = 0;

	do {
		int spent = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = i; j + 1 < 5; j += 2) {
				spent += G[p[j]][p[j + 1]];
				spent += G[p[j + 1]][p[j]];
			}
		}
		chmax(ans, spent);
	} while (next_permutation(p, p + 5));

	printf("%d\n", ans);

    return 0;
}
