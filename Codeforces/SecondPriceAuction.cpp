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

int N;
int X[MAXN];

int main(void) {
	cin >> N;

	int best = 0;
	int id = -1;

	for (int i = 0; i < N; i++) {
		cin >> X[i];

		if (X[i] > best) {
			best = X[i];
			id = i;
		}
	}

	sort(X, X + N);

	cout << id + 1 << " " << X[N - 2] << "\n";

    return 0;
}
