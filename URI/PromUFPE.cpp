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

const Int MAXN = sqrt(numeric_limits<Int>::max());
int T, N;

int main(void) {
	cin >> T;

	cout << MAXN << "\n";
	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 2; i <= N; i++) {
			
		}
		
		cout << "Caso #" << t << ": " << ans * ans << "\n";
	}
    return 0;
}
