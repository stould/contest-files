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

string S[10];

int func(char s) {
	s = tolower(s);

	if (s == 'q') {
		return 9;
	} else if (s == 'r') {
		return 5;
	} else if (s == 'b') {
		return 3;
	} else if (s == 'n') {
		return 3;
	} else if (s == 'p') {
		return 1;
	} else {
		return 0;
	}
}

int main(void) {
	int w = 0;
	int b = 0;
	
	for (int i = 0; i < 8; i++) {
		cin >> S[i];

		for (int j = 0; j < 8; j++) {
			if (isupper(S[i][j])) {
				w += func(S[i][j]);
			}
			if (islower(S[i][j])) {
				b += func(S[i][j]);
			}
		}
	}

	if (w > b) {
		cout << "White\n";
	} else if (w < b) {
		cout << "Black\n";
	} else {
		cout << "Draw\n";
	}
	
    return 0;
}
