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

int T, P;
string S;


pair<int, int> secToMin(int s) {
	return make_pair(s / 3600, (s / 60) % 60);
}

int calc(int s) {
	int ans = 0;
	pair<int, int> in = secToMin(s);

	

	return ans;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> S >> P;

		int in_sec = 3600 * (S[4] - '0') + (10 * (S[3] - '0')) + 60 * (S[1] - '0' + 10 * (S[0] - '0'));
		int range = P * in_sec / 100;

		int best = -1, ans = 0;
		
		for (int i = -range; i <= range; i++) {
			int curr = calc(in_sec + range);

			if (curr < best) {
				best = curr;
				ans = in_sec + range;
			} else if (curr == best) {
				if (abs(in_sec - curr) < abs(in_sec - ans)) {
					ans = curr;
				}
			}
		}

		cout << "CASO #" << t << ": ";

		
	}
	return 0;
}
