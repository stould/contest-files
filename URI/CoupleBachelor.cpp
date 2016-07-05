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

char buff[110];

int main(void) {
	for (int i = 1; i <= 40; i++) {
		bool ok = false;
		int l = 0, r = 0;
		for (int j = 1; j <= 1000; j++) {
			for (int k = 0; k <= j; k++) {
				if (i == j * j - k * k) {
					r = j;
					l = k;
					ok = true;
				}
			}
		}
		if (ok) {
			cout << i << " - " << r << " " << l << "\n";
		}

		
	}
    return 0;
}
