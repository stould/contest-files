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

int N;
string S;
int cnt[30];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S;
		cnt[S[0] - 'a'] += 1;
	}

	string ans = "";

	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) {
			ans += (char) ('a' + i);
		}
	}

	if (ans == "") ans = "PREDAJA";

	cout << ans << "\n";

    return 0;
}
