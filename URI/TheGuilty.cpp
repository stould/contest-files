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

const int MAXN = 60;

int N, K;
int X[MAXN];

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		for (int i = 1; i <= N; i++) {
			cin >> X[i];
		}

		cin >> K;

		for ( ; K != X[K]; ) {
			K = X[K];
		}

		cout << K << "\n";
	}
    return 0;
}
