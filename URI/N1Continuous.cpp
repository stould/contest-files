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

int T, N;

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N;
		int px, py;
		double dst = 101001010101.0;
		int id;
		cin >> px >> py;

		for (int i = 0; i < N; i++) {
			int tx, ty;
			cin >> tx >> ty;

			double d = hypot(px - tx, py - ty);
			
			if (d < dst) {
				dst = d;
				id = i + 1;
			}
		}
		cout << id << "\n";
	}
    return 0;
}
