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
string S;

bool win(char a, char b) {
	if (a == 'R') {
		return b == 'S';
	} else if (a == 'P') {
		return b == 'R';
	} else if (a == 'S') {
		return b == 'R';
	}
	return false;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> S;

		int ans = 0, c = -1;

		for (int i = 0; i < N; i++) {
			int score = 0;
			for (int j = 0; j < N; j++) {
				if (win(S[i], S[j])) {
					score += 1;				
				}
			}
			if (score > c) {
				c = score;
				ans = 1;
			} else if (score == c) {
				ans += 1;
			}
		}

		cout << "Case #" << t << ":\n" << ans;

		if (t != T) cout << "\n";
	}
    return 0;
}
