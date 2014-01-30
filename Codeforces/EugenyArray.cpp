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

const int MAXN = 200005;

int N, M;
int X[MAXN];

int main(void) {
	cin >> N >> M;

	int P = 0;

	for (int i = 1; i <= N; i++) {
		cin >> X[i];

		if (X[i] > 0) P += 1;
	}

	for (int i = 0; i < M; i++) {
		int A, B;

		cin >> A >> B;

		int len = B - A + 1;
		
		if (len % 2 == 0 && P >= len / 2 && (N - P) >= len / 2) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}

	}
    return 0;
}
