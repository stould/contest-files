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

int T;
int N;
int main(void) {
	cin >> T;

	for (int x = 1; x <= T; x++) {
		cin >> N;

		int ans = 0, cur;

		for (int j = 0; j < N; j++) {
			cin >> cur;

			chmax(ans, cur);
		}
		cout << "Case " << x << ": " << ans << "\n";
	}
    return 0;
}
