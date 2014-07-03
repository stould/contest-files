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

int T;

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		int N, S;

		cin >> N >> S;
		int ans = 1010101010, id = 0;
		for (int i = 0; i < N; i++) {
			int v;
			cin >> v;

			if (abs(v - S) < ans) {
				id = i + 1;
				ans = abs(v - S);
			}
		}
		cout << id << "\n";
	}
    return 0;
}
