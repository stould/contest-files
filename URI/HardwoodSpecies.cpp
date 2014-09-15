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

int main(void) {
	cin >> T;
	string S;
	getline(cin, S);	

	for (int t = 1; t <= T; t++) {		
		if (t == 1)	getline(cin, S);	
		double u = 0.0;

		map<string, int> mp;
		set<string> st;
		

		for ( ; getline(cin, S) && S != ""; ) {
			mp[S] += 1;
			st.insert(S);
			u += 1.0;
		}
		for (auto& it: st) {
			double per = mp[it] / u;

			cout << fixed << setprecision(4) << it << " " << 100.0 * per << "\n";
		}
		if (t != T) {
			cout << "\n";
		}
	}
    return 0;
}
