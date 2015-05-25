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

int T, N, M, C;
int P[MAXN], pos[MAXN];
bool seen[MAXN];

bool can(int u) {
	int t = 0;
	int inside = 0, last = 0;

	memset(pos, 0, sizeof(pos));
	memset(seen, 0, sizeof(seen));
	
	for (int i = 0; i < M; i++) {
		if (seen[P[i]]) {
			pos[P[i]] = i;
		} else {
			if (inside < u) {
				seen[P[i]] = true;
				pos[P[i]] = i;
				inside += 1;
				t += 1;
			} else {
				while (pos[P[last]] != last) {
					last += 1;
				}
				seen[P[last]] = false;
				seen[P[i]] = true;
				pos[P[i]] = i;
				t += 1;
				last++;

			}
		}
	}
	return t <= C;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> C;

		for (int i = 0; i < M; i++) {
			cin >> P[i];
		}

		int l = 1, h = N, m;
		int ans = INT_MAX;
		
		for ( ; l <= h; ) {
			m = (l + h) / 2;

			if (can(m)) {
				chmin(ans, m);
				h = m - 1;
			} else {
				l = m + 1;
			}
		}
		if (ans == INT_MAX) {
			ans = -1;
		}
		cout << ans << endl;
	}
	return 0;
}
