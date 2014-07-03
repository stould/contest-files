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

bool func(int x) {
	if (x <= 1) {
		return false;
	} else if (x == 2 || x == 3) {
		return true;
	} else if (x % 2 == 0) {
		return false;
	} else {
		for (int i = 3; i <= sqrt(x); i += 2) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}	
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		bool ok = true;

		if (func(N)) {
			while (N > 0) {
				int d = N % 10;
				N /= 10;
				if (d <= 1) continue;
				if (d != 2 && d != 3 && d != 5 && d != 7) {
					ok = false;
				}

			}
		} else {
			ok = false;
		}
		puts(ok ? "sim" : "nao");
	}
    return 0;
}
