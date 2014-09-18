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

int A, B, N;

int main(void) {
	cin >> A >> B >> N;
	bool ok = false;

	for (int i = 0; i < 10; i++) {
		int n = A * 10 + i;

		if (n % B == 0) {
			cout << A << i;
			for (int j = 0; j < N - 1; j++) {
				cout << "0";
			}
			ok = true;
			break;
		}
	}
	if (!ok) cout << "-1\n";
    return 0;
}
