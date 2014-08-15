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
	cin >> S;
	int N = (int) S.size();

	string ans = "";

	for (int i = 0; i < N; i++) {
		if (i + 1 < N && S[i] == S[i + 1]) {
			i += 1;
		} else {
			if (ans != "" && S[i] == ans[ans.size() - 1]) {
				ans = ans.substr(0, ans.size() - 1);
			} else {
				ans += S[i];
			}
		}
	}

	cout << ans << "\n";
    return 0;
}
