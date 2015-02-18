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

int R, N;

int main(void) {
	int t = 1;
	for ( ; cin >> R >> N && R + N != 0; ) {
		cout << "Case " << t++ << ": ";
		if (N * 27 < R) {
			cout << "impossible\n";
		} else {
			if (N >= R) {
				cout << "0\n";
			} else {
				cout << (int) ceil((R - N) / (double) N) << "\n";
			}
		}
	}
    return 0;
}
