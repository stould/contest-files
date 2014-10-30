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

int T;
Int N;
string S;

int main(void) {
	cin >> T;
	for ( ; T--; ) {
		cin >> S >> N;

		string ans = "";

		for ( ; N > 0; ) {
			N -= 1;

			ans = S[N % (int) S.size()] + ans;

			N /= (int) S.size();
		}
		cout << ans << "\n";
	}
    return 0;
}
