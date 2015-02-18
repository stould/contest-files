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

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string buf;
		cin >> buf;

		if (i % 2 == 1) {
			reverse(buf.begin(), buf.end());
		}
		S += buf;
	}
	N = (int) S.size();
	int ans = 0, curr = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'o') {
			curr += 1;
		} else if (S[i] == 'A') {
			ans = max(ans, curr);
			curr = 0;
		}
	}
	ans = max(ans, curr);
	cout << ans << endl;

    return 0;
}
