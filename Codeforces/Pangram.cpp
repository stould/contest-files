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
map<char, int> cnt;

int main(void) {
	cin >> N >> S;

	bool ok = true;
	
	for (int i = 0; i < N; i++) {
		cnt[tolower(S[i])] += 1;
	}

	for (char c = 'a'; c <= 'z'; c++) {
		if (!cnt[c]) {
			ok = false;
		}
	}

	if (ok) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}
