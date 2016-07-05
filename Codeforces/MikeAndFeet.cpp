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

const int MAXN = 100005;
const int MAXV = 2000000001;
int N, P[MAXN];
int L[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		L[i] = MAXN;
	}

	for (int i = 0; i < N; i++) {
		L[i] = min(L[i], P[i]);
		L[N - i - 1] = min(L[N - i - 1], P[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << L[i] << " ";
	}
	cout << "\n";

	return 0;
}
