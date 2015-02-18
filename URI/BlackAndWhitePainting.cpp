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

int N, M, C;

int main(void) {
	for ( ; cin >> N >> M >> C; ) {
		if (N == 0 && M == 0 && C == 0) break;
	
		Int ans = 0LL;

		N -= 7;
		M -= 7;
	
		if (C == 1) {
			N += 1;
		}
		
		ans += ((N + 1) / 2) * (M / 2);
		ans += (N / 2) * ((M + 1) / 2);

		cout << ans << "\n";
	}
    return 0;
}
