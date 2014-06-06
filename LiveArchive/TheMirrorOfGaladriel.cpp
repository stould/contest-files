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
		cin >> S;

		int N = (int) S.size();
		bool ok = true;

		set<string> s;

		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N - i; j++) {
				string sp = S.substr(i, j);
				s.insert(sp);
			}
		}
		
		for (auto it = s.begin(); it != s.end(); it++) {
			string sp = *it;
			reverse(sp.begin(), sp.end());
			
			if (!s.count(sp)) {
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
    return 0;
}
