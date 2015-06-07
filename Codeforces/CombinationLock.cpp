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
string S, T;

int main(void) {
	cin >> N >> S >> T;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int ds = S[i] - '0';
		int dt = T[i] - '0';
		
		ans += min(abs(ds - dt), min(ds + 9 - dt + 1, 9 - ds + dt + 1));

	}
	
	cout << ans << "\n";
	
	return 0;
}
