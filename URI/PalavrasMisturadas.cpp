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

int main(void) {
	for ( ; getline(cin, S); ) {
		istringstream ss(S);
		string tmp;
		vector<string> ans;
		for ( ;ss >> tmp; ) {
			reverse(tmp.begin(), tmp.end());
			ans.push_back(tmp);
		}
		for (int i = 0; i < (int) ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size() - 1) {
				cout << " ";
			} else {
				cout << "\n";
			}
		}
	}
    return 0;
}
