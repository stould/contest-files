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

int A, B, N, L, T, M;

Int sum_to_i(int i) {
	Int ai = A + (i - 1) * B;

	return i * (A + ai) / 2;
}

Int sum(int l, int r) {
	return sum_to_i(r) - sum_to_i(l - 1);
}

int main(void) {
	cin >> A >> B >> N;

	for (int i = 0; i < N; i++) {
		cin >> L >> T >> M;

		Int l = 0, h = 10, m;
		int best = -1;

		while (l <= h) {
			m = (l + h) / 2;

			Int curr = sum(L, L + m) - T * M;

			if (curr <= 0 && A + (L + m - 1) * B <= T * M) {
				l = m + 1;
				best = max(best, L + (int) m);
			} else {
				h = m - 1;
			}
		}
		cout << best << endl;
	}
	
	return 0;
}
