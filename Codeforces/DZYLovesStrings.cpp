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
int N;
int V[30];
map<char, int> mp;
int main(void) {
	cin >> S >> N;

	int p = 0;
	char best = '$';

	for (int i = 0; i < 26; i++) {
		cin >> V[i];
		if (V[i] > p) {
			p = V[i];
			best = 'a' + i;
		}
		mp['a' + i] = V[i];
	}

	int ans = 0;

	for (int i = 0; i < (int) S.size(); i++) {
		ans += (i + 1) * mp[S[i]];
	}

	for (int i = (int) S.size(); i < S.size() + N; i++) {
		ans += (i + 1) * mp[best];
	}

	cout << ans << endl;

    return 0;
}
