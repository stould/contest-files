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

int K, N, W;

int main(void) {
	cin >> K >> N >> W;

	int ans = 0;

	for (int i = 1; i <= W; i++) {
		if (N == 0) {
			ans += K * i;
		} else {
			if (N - K * i < 0) {
				ans += K * i - N;
				N = 0;					
			} else {
				N -= K * i;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
