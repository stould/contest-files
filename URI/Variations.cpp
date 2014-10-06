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
string S;

int main(void) {
	cin >> T;

	map<char, int> mp;

	for (char c = 'a'; c <= 'z'; c++) {
		mp[c] = 2;
	}

	mp['a'] += 1;
	mp['e'] += 1;
	mp['i'] += 1;
	mp['o'] += 1;
	mp['s'] += 1;

	for (int t = 1; t <= T; t++) {
		cin >> S;
		Int ans = 1LL;

		for (int i = 0; i < (int) S.size(); i++) {
			ans *= mp[tolower(S[i])];
		}

		cout << ans << "\n";
	}
    return 0;
}
