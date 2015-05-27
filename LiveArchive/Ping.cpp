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
	while (cin >> S && S != "0") {
		vector<int> ans;
		for (int i = 1; i < (int) S.size(); i++) {
			if (S[i] == '1') {
				ans.push_back(i);
				for (int j = i; j < (int) S.size(); j += i) {
					if (S[j] == '0') {
						S[j] = '1';
					} else {
						S[j] = '0';
					}
				}
			}
		}
		for (int i = 0; i < (int) ans.size(); i++) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << "\n";
	}
	return 0;
}
