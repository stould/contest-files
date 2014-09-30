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

int A[3], B[3], N;

int main(void) {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < 3; i++) {
		scanf("%d", &B[i]);
	}
	scanf("%d", &N);
	
	bool ok = true;
	
	for (int i = 0; i < N; i++) {
		int used = 0;
		for (int j = 0; j < 3; j++) {
			if (A[j] > 0) {
				if (A[j] + used <= 5) {
					used += A[j];
					A[j] = 0;
				} else {
					A[j] -= (5 - used);
					used = 5;
				}
			}
		}
		if (!used) {
			for (int j = 0; j < 3; j++) {
				if (B[j] > 0) {
					if (B[j] + used <= 10) {
						used += B[j];
						B[j] = 0;
					} else {
						B[j] -= (10 - used);
						used = 10;
					}
				}
			}			
		}
	}
	
	for (int i = 0; i < 3; i++) {
		if (A[i] > 0) ok = false;
	}

	for (int i = 0; i < 3; i++) {
		if (B[i] > 0) ok = false;
	}

	puts(ok ? "YES" : "NO");

	
	
    return 0;
}
