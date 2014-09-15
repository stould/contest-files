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

const int MAXN = 1010;

int N, M;
int P[MAXN];

int main(void) {
	cin >> N >> M;
	
	int ans = 0, buff = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	
	for (int i = 0; i < N; i++) {
		P[i] += buff;
		buff = 0;

		if (P[i] > M) {
			ans += P[i] - M;
			buff = -(P[i] - M);
		} else if (P[i] < M) {
			ans += M - P[i];
			buff = M - P[i];
		}
	}

	cout << ans << "\n";

    return 0;
}
