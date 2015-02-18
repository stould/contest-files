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


string func(string p) {
	string ans = "";

	for (int i = 0; i < p.size(); i++) {
		if (p[i] != ' ') {
			int pos = 0;
			if (islower(p[i])) {
				pos = ((((p[i] - 'a' - 13) % 26) + 26) % 26);
				ans += 'a' + pos;
			} else {
				pos = ((((p[i] - 'A' - 13) % 26) + 26) % 26);
				ans += 'A' + pos;
			}
		} else {
			ans += " ";
		}
	}

	return ans;
}

int main(void) {
	for ( ; getline(cin, S); ) {
		string p = "";
		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] == ' ') {
				p += S[i];
				continue;
			}
			if (i % 2 == 1) {
				p += S[i];
			}
		}
		cout << func(p) << "\n";
	}
    return 0;
}
