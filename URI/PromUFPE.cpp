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

const Int MAXN = sqrt(numeric_limits<Int>::max());
int T, N;

int main(void) {
	cin >> T;

	cout << MAXN << "\n";
	for (int t = 1; t <= T; t++) {
		cin >> N;

		Int ans = sqrt(N);
		Int l = ans + (N - ans) / 2;
		int r = ans + (N - ans) / 2;
		
		while (1) {
			if ((l * l) % N == 0) {
				ans = l;
				break;
			}
			if ((r * r) % N == 0) {
				ans = r;
				break;
			}
			if (l != ans) {
				l -= 1;
			}
			if (r != N) {
				r += 1;
			}
		}
		
		cout << "Caso #" << t << ": " << ans * ans << "\n";
	}
    return 0;
}
