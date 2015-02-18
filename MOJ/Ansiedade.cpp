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

string S[10];

int main(void) {
	int ans = 0;
	for ( ; cin >> S[0]; ) {
		for (int i = 1; i < 10; i++) {
			cin >> S[i];
		}
		int c = 0;
		for (int i = 0; i < 10; i++) {
			if (S[i] == "sim") c++;
		}
		if (c > 1) {
			ans += 1;
		}
	}
	cout << ans << "\n";
    return 0;
}
