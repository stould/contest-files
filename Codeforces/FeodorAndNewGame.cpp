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

int N, M, K;
int P[1010];

int main(void) {
	cin >> N >> M >> K;

	int ans = 0;

	for (int i = 0; i <= M; i++) {
		cin >> P[i];
	}
	
	for (int j = 0; j < M; j++) {
		int d = __builtin_popcount(P[j] ^ P[M]);
		
		if (d <= K) ans += 1;	
	}
	
	cout << ans << "\n";
	
    return 0;
}
