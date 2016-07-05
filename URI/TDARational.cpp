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

int T;

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int A, B, C, D;
		char O;
		scanf("%d / %d %c %d / %d", &A, &B, &O, &C, &D);

		int na = 0;
		int db = 0;

		if  (O == '+') {
			na = A * D + B * C;
			db = B * D;
		} else if (O == '-') {
			na = A * D - B * C;
			db = B * D;
		} else if (O == '*') {
			na = A * C;
			db = B * D;
		} else {
			na = A * D;
			db = B * C;
		}

		int nma = na / gcd(na, db);
		int dba = db / gcd(na, db);

		if (dba < 0) {
			nma = -nma;
			dba = -dba;
		}		
		
		printf("%d/%d = %d/%d\n", na, db, nma, dba);
	}
	return 0;
}
