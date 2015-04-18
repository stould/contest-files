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

const int MAXN = 1010;
int T, N;
int P[MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		int best = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			chmax(best, P[i]);
		}

		int ans = INT_MAX;

		for (int i = 1; i <= best; i++) {
			int now = i;
			for (int j = 0; j < N; j++) {
				if (P[j] > i) {
					now += (P[j] - i) / i + (((P[j] - i) % i) != 0);
				}
			}
			chmin(ans, now);
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}
    return 0;
}
