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

int P[4];

int main(void) {
	for (int i = 0; i < 4; i++) {
		cin >> P[i];
	}
	sort(P, P + 4);
	if (P[0] + P[1] > P[2] || P[1] + P[2] > P[3]) {
		cout << "S\n";
	} else {
		cout << "N\n";
	}
    return 0;
}
