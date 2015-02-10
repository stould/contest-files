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
	for ( ; cin >> S; ) {
		int b1 = 0;
		int b2 = 0;
		int mul = 1;

		for (int i = 0; i < S.size() - 3; i++) {
			if (S[i] != '.') {
				b1 += (S[i] - '0') * mul;
				b2 += (S[i] - '0') * (10 - mul);
				mul++;
			}
		}
		
		b1 %= 11;
		b2 %= 11;

		if (b1 == 10) {
			b1 = 0;
		}
		if (b2 == 10) {
			b2 = 0;
		}

		if ((S[S.size() - 2] - '0') == b1 && (S[S.size() - 1] - '0') == b2) {
			cout << "CPF valido" << endl;
		} else {
			cout << "CPF invalido" << endl;
		}
	}
    return 0;
}
