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

int A[2], B[2], AA, BB;

int main(void) {
	for (int i = 0; i < 2; i++) {
		cin >> A[i] >> B[i];
	}
	cin >> AA >> BB;

	bool ok = false;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (i != j) {
				if (A[i] >= AA && B[i] >= BB) {
					ok = true;
				}
				if (A[i] >= BB && B[i] >= AA) {
					ok = true;
				}
				if (A[i] + A[j] >= AA && min(B[i], B[j]) >= BB) {
					ok = true;
				}
				if (A[i] + A[j] >= BB && min(B[i], B[j]) >= AA) {
					ok = true;
				}
				if (A[i] + B[j] >= AA && min(B[i], A[j]) >= BB) {
					ok = true;
				}
				if (A[i] + B[j] >= BB && min(B[i], A[j]) >= AA) {
					ok = true;
				}
				if (B[i] + B[j] >= AA && min(A[i], A[j]) >= BB) {
					ok = true;
				}
				if (B[i] + B[j] >= BB && min(B[i], B[j]) >= AA) {
					ok = true;
				}

			}
		}
	}
	if (ok) {
		cout << "S\n";
	} else {
		cout << "N\n";
	}
	
	
    return 0;
}
