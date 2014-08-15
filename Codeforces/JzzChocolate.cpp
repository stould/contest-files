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

int main(void) {
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		if (N == 1 && M == 1) {
			cout << "-1\n";
			return 0;
		}
		if (N < M) {
			swap(N, M);
		}
		if (N % 2 == 0) {
			N /= 2;
		} else {
			if (M % 2 == 0) {
				M /= 2;
			} else {
				N = (N + 1) / 2;
			}
		}		
	}
	cout << N * M << "\n";
    return 0;
}
