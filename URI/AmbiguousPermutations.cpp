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

int N;
int P[1000005];

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		bool ok = true;

		for (int i = 0; i < N; i++) {
			if (P[P[i] - 1] - 1 != i) {
				ok = false;
			}
		}

		if (ok) {
			cout << "ambiguous\n";
		} else {
			cout << "not ambiguous\n";
		}
	}
    return 0;
}
