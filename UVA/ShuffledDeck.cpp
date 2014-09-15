
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

const int MAXN = 200005;

int P;
int S[MAXN];

int main(void) {
	for ( ; cin >> P; ) {
		int pos = 0;

		for (int x = 1; x <= P; x++) {
			if (pos < P / 2) {
				pos = 2 * pos + 1;
			} else {
				pos = (pos - P / 2) * 2;
			}
			if (pos == 0) {
				cout << x << "\n";
				break;
			}
		}
	}
    return 0;
}
