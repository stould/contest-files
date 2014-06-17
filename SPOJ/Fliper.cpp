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

int A, B;

int main(void) {
	cin >> A >> B;
	if (A == 0) {
		cout << "C\n";
	} else {
		if (B == 0) {
			cout << "B\n";
		} else {
			cout << "A\n";
		}
	}
    return 0;
}
