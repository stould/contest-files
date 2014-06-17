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

int N, M;
int MT[510][510];

int main(void) {
	scanf("%d%d", &N, &M);
	bool ok = true, all_zero = false;
	int last = -1;

	for (int i = 0; i < N; i++) {
		int pos = last, h = 0, zero = 0;
		for (int j = 0; j < M; j++) {
			scanf("%d", &MT[i][j]);
			if (MT[i][j] == 0) {
				zero += 1;
			} else {
				if (h == 0) {
					h = 1;
					pos = j;
				}
			}			
			if (j <= last) {
				if (MT[i][j] != 0) {
					ok = false;
				}
			}
		}
		if (zero == M) {
			all_zero = true;
		} else {
			if (all_zero) {
				ok = false;
			}
		}
		last = max(last, pos);
	}
	puts(ok ? "S" : "N");
    return 0;
}
