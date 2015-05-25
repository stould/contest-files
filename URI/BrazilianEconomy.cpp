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

int N;

int main(void) {
	while (cin >> N) {
		int P, C = 0;
		for (int i = 0; i < N; i++) {
			cin >> P;
			if (P == 0) {
				C += 1;
			}
		}
		if (C > (N / 2)) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
	}
	return 0;
}
