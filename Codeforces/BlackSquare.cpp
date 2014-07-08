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

int A[5];
string S;

int main(void) {
	for (int i = 1; i <= 4; i++) {
		cin >> A[i];
	}
	cin >> S;
	int ans = 0;

	for (int i = 0; i < (int) S.size(); i++) {
		ans += A[S[i] - '0'];
	}
	cout << ans << "\n";
    return 0;
}
