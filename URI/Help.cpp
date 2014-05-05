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
int pen[30];

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		char c;
		int t;

		memset(pen, 0, sizeof(pen));
		
		string s;
		int ans = 0, p = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> c >> t >> s;

			if (s[0] == 'c') {
				ans += 1;
				p += pen[c - 'A'] + t;
			} else {
				pen[c - 'A'] += 20;
			}		
		}
		cout << ans << " " << p << "\n";
	}
    return 0;
}
