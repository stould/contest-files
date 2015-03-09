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

int T, X, Y, K, N;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> X >> Y >> K >> N;

		int P, C;
		bool ok = false;
		
		for (int i = 0; i < N; i++) {
			cin >> P >> C;

			if (C > K) continue;

			if (Y + P >= X) {
				ok = true;
			}
		}

		if (ok) {
			cout << "LuckyChef" << endl;
		} else {
			cout << "UnluckyChef" << endl;
		}
	}
    return 0;
}
