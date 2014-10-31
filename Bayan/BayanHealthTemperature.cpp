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

int T, W, R, M, S;

int main(void) {
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> W >> R >> M >> S;

		cout << "Case #" << t << ":\n";

		int h = (S / 60) / 60;
		int m = (S % 60);

		bool already = false;

		if (M >= 10) {
			cout << "NOTHING\n";
			already = true;
		} else if (R < 40 || W < 35) {
			cout << "EMERGENCY\n";
		} else if (R > 60) {
			cout << "NIGHTMARE\n";
		} else if (h > 8 || (h == 8 && m > 0)) {
			cout << "WAKE-UP\n";
		} else {
			if (!already) {
				cout << "NOTHING\n";
			}
		}
	}
    return 0;
}
