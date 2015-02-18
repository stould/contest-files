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

	for ( ; T--; ) {
		cin.ignore();
		getline(cin, S);
		set<char> s;
		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] >= 'a' && S[i] <= 'z') {
				s.insert(S[i]);
			}
		}
		int p = (int) s.size();

		if (p == 26) {
			cout << "frase completa\n";
		} else if (p >= 13) {
			cout << "frase quase completa\n";
		} else {
			cout << "frase mal elaborada\n";
		}
	}
    return 0;
}
