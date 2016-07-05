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
int keys[50];

int main(void) {
	cin >> N >> S;

	int ans = 0;
	
	for (int i = 0; i < 2 * N - 2; i += 2) {
		keys[S[i] - 'a'] += 1;

		if (keys[S[i + 1] - 'A'] == 0) {
			ans += 1;
		} else {
			keys[S[i + 1] - 'A'] -= 1;
		}
	}

	cout << ans << endl;
	
	return 0;
}
