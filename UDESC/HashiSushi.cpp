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

const int MAXN = 60;

int T, N;
int C[MAXN];
int P[4 * MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cout << "CASO #" << t << ": ";

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> C[i];
		}
		
		sort(C, C + N);

		for (int i = 0; i < 4 * N; i++) {
			cin >> P[i];
		}

		sort(P, P + 4 * N);
		reverse(P, P + 4 * N);

		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				//cout << C[i] << " " << P[j] << endl;
				ans = max(ans, C[i] + P[i * 4 + j]);
			}
		}

		cout << ans << endl;
	}
	return 0;
}
