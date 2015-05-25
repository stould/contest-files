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

string S[5];

int main(void) {
	for (int i = 0; i < 4; i++) {
		cin >> S[i];
	}

	int F = 0, L = 0;

	for (int i = 0; i < 4; i++) {
		F = F * 10 + (S[i][0] - '0');
		L = L * 10 + (S[i][S[i].size() - 1] - '0');
	}

	for (int i = 1; i < (int) S[0].size() - 1; i++) {
		int C = 0;
		for (int j = 0; j < 4; j++) {
			C = C * 10 + (S[j][i] - '0');
		}
		cout << char((F * C + L) % 257);
	}
	cout << endl;
	
	return 0;
}
