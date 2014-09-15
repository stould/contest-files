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

string A, B;
int T;
int main(void) {
	cin >> T;
	for ( ; T--; ) {
		cin >> A >> B;
		int ans = 0, N = (int) A.size(); 

		for (int i = 0; i < N; i++) {
			if (A[i] < B[i]) {
				ans += (int) (B[i] - A[i]);
			} else if (B[i] < A[i]) {
				ans += (int) (B[i] - 'a' + 1) + (int) ('z' - A[i]);
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
