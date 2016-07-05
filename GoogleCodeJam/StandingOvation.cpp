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

int T, N;
int lvl[10010];
string S;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> S;

		int ans = 0, stand = 0;
		
		for (int i = 0; i < N + 1; i++) {
			lvl[i] = S[i] - '0';

			if (i > stand) {
				ans += i - stand;
				stand += i - stand;
			}
			stand += lvl[i];
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}
    return 0;
}
