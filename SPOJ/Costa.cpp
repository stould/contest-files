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

int N, M;
string S[MAXN];
int vis[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	memset(vis, false, sizeof(vis));
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == '.') continue;
			bool out = false;
			for (int k = 0; k < 4; k++) {
				int px = i + dx[k];
				int py = j + dy[k];

				if (px >= 0 && py >= 0 && px < N && py < N) {
					if (S[px][py] == '.') {
						out = true;
					}
				} else {
					out = true;
				}
			}
			if (out) {
				ans += 1;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
