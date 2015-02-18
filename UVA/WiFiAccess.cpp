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

const int MAXN = 110;

int T, N, M;
int Rx[MAXN], Ry[MAXN], Rr[MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> Rx[i] >> Ry[i] >> Rr[i];
		}

		cout << "Case " << t << ":\n";

		for (int i = 0; i < M; i++) {
			bool ok = false;

			int X, Y;
			cin >> X >> Y;

			for (int j = 0; !ok && j < N; j++) {
				double dst = hypot(Rx[j] - X, Ry[j] - Y);

				if (dst <= Rr[j]) {
					ok = true;
				}
			}

			if (ok) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
    return 0;
}
