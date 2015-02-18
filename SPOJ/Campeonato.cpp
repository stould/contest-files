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

int C[3], F[3];

int main(void) {
	for (int i = 0; i < 3; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> F[i];
	}
	int PC = C[0] * 3 + C[1];
	int PF = F[0] * 3 + F[1];

	char W = 'P';

	if (PC != PF) {
		W = PC > PF ? 'C' : 'F';
	} else {
		if (C[2] != F[2]) {
			W = C[2] > F[2] ? 'C' : 'F';
		} else {
			W = '=';
		}
	}
	cout << W << "\n";
    return 0;
}
