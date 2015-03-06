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

const int MAXN = 100005;

int T, N, P[MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		int best = -1;
		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];

			if (P[i] > best) {
				best = P[i];
			}
		}

		for (int i = 0; i < N; i++) {
			if (P[i] == best) {
				int len = 1;
				int j = i + 1;

				while (j < N && P[j] == best) {
					j += 1;
					len += 1;
				}

				ans = max(ans, len);
				i = j;
			}
		}
		cout << "Caso #" << t << ": " << ans << "\n";
	}
    return 0;
}
