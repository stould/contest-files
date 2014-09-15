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

string S, T;

int main(void) {
	cin >> S >> T;

	bool arr = false;
	bool aut = false;
	bool both = false;

	string par = S, part = T;
	sort(par.begin(), par.end());
	sort(part.begin(), part.end());

	if (par == part) arr = true;

	int ps = 0;
	for (int i = 0; ps < T.size() && i < S.size(); i++) {
		if (T[ps] == S[i]) ps++;
	}

	int ps2 = 0;
	for (int i = 0; ps < part.size() && i < par.size(); i++) {
		if (part[ps2] == par[i]) ps2++;
	}

	if (ps2 == part.size()) both = true;
	if (ps == T.size()) aut = true;

	
	if (arr) {
		puts("array");
	} else if (aut) {
		puts("automaton");
	} else if (both) {
		puts("both");
	} else {
		puts("need tree");
	}
	
    return 0;
}
