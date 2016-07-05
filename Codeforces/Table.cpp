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

int N, M, P;

int main(void) {
	cin >> N >> M;

	int ans = 100;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> P;

			if (P == 1) {
				if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
					chmin(ans, 2);
				} else {
					chmin(ans, 4);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
