#include <iostream>
#include <cstdio>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

string S;

int main(void) {
	freopen("cowfind.in", "r", stdin);
	freopen("cowfind.out", "w", stdout);
	cin >> S;
	int N = (int) S.size();

	Int found = 0LL, ans = 0LL;

	for (int i = 0; i < N - 1; i++) {
		if (S[i] == '(' && S[i + 1] == '(') {
			found += 1;
		} else if (S[i] == ')' && S[i + 1] == ')') {
			ans += found;
		}
	}

	cout << ans << "\n";
    return 0;
}
