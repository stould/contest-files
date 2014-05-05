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

string S;
int P;

int main(void) {
	for ( ; cin >> S >> P; ) {
		int ans = 0;

		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] == 'W') {
				ans += 1;
			} else {
				int j = i, d = 0;
				for ( ; j < (int) S.size() && S[j] == 'R'; j++) {
					d += 1;
				}
				ans += ceil(d / (double) P);
				i = j - 1;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
