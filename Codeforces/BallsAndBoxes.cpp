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
const Int INF = 1001010010010100LL;

int N, X;
Int P[MAXN];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> X;

	X -= 1;

	Int L = INF;

	for (int i = 0; i < N; i++) {
		cin >> P[i];

		L = min(L, P[i]);
	}
	
	for (int i = 0; i < N; i++) {
		P[i] -= L;
	}

	int ps = X, sum = 0;
	
	for ( ; ; ) {
		if (P[ps] == 0) break;
		P[ps] -= 1;
		sum += 1;
		ps = (ps - 1 + N) % N;
	}

	P[ps] += sum + (L * N);
	
	for (int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}
	cout << "\n";

    return 0;
}
