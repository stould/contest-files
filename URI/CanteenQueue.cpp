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

int T, N;
int X[1010], S[1010];

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> S[i];
			X[i] = S[i];
		}
		sort(X, X + N);
		reverse(X, X +N);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (X[i] == S[i]) ans += 1;
		}
		cout << ans << "\n";
	}
    return 0;
}
