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

int T, pos, st, ed;
string S, OP, app;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> S;
		for ( ; cin >> OP && OP != "END"; ) {
			if (OP == "I") {
				cin >> app >> pos;
				S.insert(pos, app);
			} else {
				cin >> st >> pos;				
				cout << S.substr(st, pos - st + 1) << "\n";
			}
		}
	}
    return 0;
}
