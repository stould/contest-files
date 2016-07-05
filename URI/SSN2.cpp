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

string S;

int main(void) {
	while (cin >> S) {
		int b1 = 0;
		int b2 = 0;

		for (int i = 0; i < 9; i++) {
			int d = S[i] - '0';

			b1 += (i + 1) * d;
			b2 += (9 - i) * d;
		}

		b1 %= 11;
		b2 %= 11;

		if (b1 == 10) b1 = 0;
		if (b2 == 10) b2 = 0;

		for (int i = 0; i < 9; i++) {
			if (i != 0 && i % 3 == 0) {
				cout << ".";
			}
			cout << S[i];
		}
		cout << "-" << b1 << b2 << "\n";
	}
    return 0;
}
