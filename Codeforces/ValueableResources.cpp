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

const Int INF = 1000000000005LL;
int N;

int main(void) {
	cin >> N;

	Int X, Y;
	Int L = INF, U =-INF;
	Int D = INF, R =-INF;

	for (int i = 0; i < N; i++) {
		cin >> X >> Y;

		L = min(L, X);
		R = max(R, X);

		U = max(U, Y);
		D = min(D, Y);
	}

	Int s = max(R - L, U - D);
	
	cout << s * s << "\n";
	
    return 0;
}
