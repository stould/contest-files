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

int T, C, D;
string S;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> C >> D >> S;
		
		int ans = 0, pos = 0;

		while (1) {
			bool walk = false;

			for (int i = D + 1; i >= 1; i--) {
				int npos = min(C - 1, pos + i);

				if (S[npos] == '.') {
					ans += 1;
					pos = npos;
					walk = true;
					break;
				}
			}
			if (pos == C - 1) break;
			if (!walk) {
				ans = 0;
				break;
			}
		}
		cout << "Caso #" << t << ": " << ans << endl;
	}
	return 0;
}
