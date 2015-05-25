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

int fi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			result -= result / i;
		}
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n > 1) {
		result -= result / n;
	}
	return result;
}

int main(void) {
	while (cin >> N) {
		if (N == 2147483647) {
			cout << 1073741823 << endl;
		} else {
			cout << fi(N) / 2 << endl;
		}
	}	
	return 0;
}
