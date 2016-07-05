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

int A, B, C, D;

int point(int p, int t) {
	return max(3 * p / 10, p - p * t / 250);
}

int main(void) {
	cin >> A >> B >> C >> D;

	int M = point(A, C);
	int V = point(B, D);

	if (M > V) {
		cout << "Misha" << endl;
	} else if (V > M) {
		cout << "Vasya" << endl;
	} else {
		cout << "Tie" << endl;
	}
	
	return 0;
}
