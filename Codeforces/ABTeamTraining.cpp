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

int N, M;

int main(void) {
	cin >> N >> M;

	int ans = 0;

	while (N > 0 && M > 0) {
		if (N >= M) {
			if (N - 2 >= 0 && M - 1 >= 0) {
				N -= 2;
				M -= 1;
				
				ans += 1;
			} else {
				break;
			}
		} else {
			if (N - 1 >= 0 && M - 2 >= 0) {
				N -= 1;
				M -= 2;

				ans += 1;
			} else {
				break;
			}				
		}
	}

	cout << ans << "\n";
	
    return 0;
}
