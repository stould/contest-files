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
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);;
	
	cin >> S >> T;
	
	for (int i = 0; i <= (int) S.size() - T.size(); i++) {
		if (S.substr(i, T.size()) == T) {
			S = S.substr(0, i) + S.substr(i + T.size(), S.size() - i - T.size());
			i = max(0, i - (int) T.size());
		}
	}
	
	cout << S << "\n";
	
    return 0;
}
