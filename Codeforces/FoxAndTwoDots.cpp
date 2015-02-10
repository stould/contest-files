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

const int MAXN = 55;
const int INF = 100101010;

int N, M;
string S[MAXN];
bool vis[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool dfs(int x, int y, int fx, int fy) {
	vis[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M && !(nx == fx && ny == fy)) {
			if (S[nx][ny] == S[x][y]) {
				if (vis[nx][ny]) {
					return true;
				} else {
					if (dfs(nx, ny, x, y)) {
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	bool ok = false;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vis[i][j]) {
				ok |= dfs(i, j, -1, -1);
			}
		}
	}

	if (ok) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
    return 0;
}
