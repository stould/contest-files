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

bool isV(char c) {
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main(void) {
	cin >> T;

	for (int i = 0; i < T; i++) {
		string S;
		
		cin >> S;

		int c = 0, v = 0;
		
		for (int i = 0; i < (int) S.size(); i++) {
			if (isV(S[i])) {
				v += 1;
			} else {
				c += 1;
			}
		}
		
		cout << S << endl;

		if (v > c) {
			cout << "1";
		} else {
			cout << "0";
		}
		cout << endl;
	}
	return 0;

}
