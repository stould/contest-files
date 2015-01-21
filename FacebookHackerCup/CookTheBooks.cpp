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

string fa(string p) {
	int pos = 0;
	char val = p[0];
	
	for (int i = 1; i < p.size(); i++) {
		if (p[i] < val && p[i] != '0') {
			pos = i;
			val = p[i];
		}
	}

	swap(p[0], p[pos]);
	
	return p;
}

string fb(string p) {
	int pos = 0;
	char val = p[0];
	
	for (int i = 1; i < p.size(); i++) {
		if (p[i] >= val) {
			pos = i;
			val = p[i];
		}
	}

	swap(p[0], p[pos]);

	return p;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> S;

		cout << "Case #" << t << ": " << fa(S) << " " << fb(S) << "\n";		
	}
	
    return 0;
}
