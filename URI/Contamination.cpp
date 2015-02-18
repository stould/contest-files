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

int N, M;
string S[MAXN];
bool vis[MAXN][MAXN];

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return;
	
	if (S[x][y] == 'X' || vis[x][y]) return;

	vis[x][y] = true;
	S[x][y] = 'T';

	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

int main(void) {
	for ( ; cin >> N >> M && !(N == 0 && M == 0); ) {
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'T' && !vis[i][j]) {
					dfs(i, j);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			cout << S[i] << "\n";
		}
		cout << "\n";
	}
    return 0;
}
