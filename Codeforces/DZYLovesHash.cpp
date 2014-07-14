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

int P, N;
int B[MAXN];

int main(void) {
	cin >> P >> N;

	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		B[X % P] += 1;
		
		if (B[X % P] > 1) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
    return 0;
}
