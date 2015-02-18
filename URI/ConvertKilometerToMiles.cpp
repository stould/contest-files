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

const int MAXF = 24;

int T, N;
int F[MAXF + 5];

int main(void) {
	cin >> T;

	F[1] = 1;
	F[2] = 2;

	for (int i = 3; i <= MAXF; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}

	for ( ; T--; ) {
		cin >> N;

		int ans = 0;

		for (int i = MAXF; i >= 1; i--) {
			if (N - F[i] >= 0) {
				ans += F[i - 1];
				N -= F[i];
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
