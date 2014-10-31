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
string S;
int main(void) {
	cin >> T;
	for ( ; T--; ) {
		cin >> S;

		int cnt = 0;

		for (const auto& c: S) {
			if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
				cnt += 1;
			}
		}
		if (cnt % 2 == 1) {
			cout << "PESAR" << endl;
		} else {
			cout << "DOKHTAR" << endl;
		}
	}
    return 0;
}
