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

int N, X;
int P[MAXN];

int main(void) {
	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P, P + N);

	Int ans = 0LL;

	for (int i = 0; i < N; i++) {
		ans += (Int) P[i] * X;
		X = max(1, X - 1);
	}
	
	cout << ans << "\n";

    return 0;
}
