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

const double EPS = 1e-7;

int N;
double X[12], Y[12], R[12];
	
int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i] >> R[i];
	}

	int ans = 0;
	
	for (int x = 1; x <= 1000; x++) {
		for (int y = 1; y <= 1000; y++) {
			int cnt = 0;

			for (int i = 0; i < N; i++) {
				double dst = hypot(x - X[i], y - Y[i]);

				if (dst - EPS <= R[i]) {
					cnt += 1;
				}
			}
			if (cnt > 1) ans += 1;
		}
	}

	cout << ans << "\n";
	
    return 0;
}
