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

int N, M, X;
int B[110], G[110];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X;
		B[X] += 1;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> X;
		G[X] += 1;
	}

	int ans = 0;

	for (int i = 1; i <= 100; i++) {
		while (i - 1 >= 1 && B[i] > 0 && G[i - 1] > 0) {
			B[i] -= 1;
			G[i - 1] -= 1;
			ans += 1;
			}
		while (B[i] > 0 && G[i] > 0) {
			B[i] -= 1;
			G[i] -= 1;
			ans += 1;
		}
		while (i + 1 <= 100 && B[i] > 0 && G[i + 1] > 0) {
			B[i] -= 1;
			G[i + 1] -= 1;
			ans += 1;
		}
	}
	
	
	cout << ans << "\n";
	
    return 0;
}
