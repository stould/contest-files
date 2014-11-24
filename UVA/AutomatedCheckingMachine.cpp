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

int A[6], B[6];

int main(void) {
	for ( ; ; ) {
		for (int i = 0; i < 5; i++) {
			if (scanf("%d", &A[i]) != 1) {
				return 0;
			}
		}
		bool ok = true;
		for (int i = 0; i < 5; i++) {
			if (scanf("%d", &B[i]) != 1) {
				return 0;
			}
			if (A[i] == B[i]) {
				ok = false;
			}
		}
		if (ok) {
			printf("Y\n");		   
		} else {
			printf("N\n");
		}

	}
	
    return 0;
}
