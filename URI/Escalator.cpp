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

int main(void) {
	while (cin >> N && N != 0) {
		int ans = 0, last = -10, curr;
		for (int i = 0; i < N; i++) {
			cin >> curr;
			if (curr - last < 10) {
				ans += curr - last;
			} else {
				ans += 10;
			}			
			last = curr;
		}
		cout << ans << "\n";
	}
    return 0;
}
