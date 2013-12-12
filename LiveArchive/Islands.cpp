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

const int MAXN = 9010;

int T, Z;
int N, M;

int arr[MAXN][MAXN];
int vis[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int curr) {
	vis[x][y] = 1;

	int k;

	for (k = 0; k < 4; k++) {
		int xx = x + dx[k];
		int yy = y + dy[k];

		if (xx >= 0 && yy >= 0 && xx < N && yy < M && !vis[xx][yy] && arr[xx][yy] > curr) {
			dfs(xx, yy, curr);
		}
	}
}

int main(void) {
	Z = in();

	int i, j, x;
	int curr;

	for ( ; Z--; ) {
		N = in();
		M = in();

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				arr[i][j] = in();
			}
		}

		T = in();

		for (x = 0; x < T; x++) {
			int ans = 0;

			curr = in();

			memset(vis, 0, sizeof(vis));

			for (i = 0; i < N; i++) {
				for (j = 0; j < M; j++) {
					if (arr[i][j] > curr && !vis[i][j]) {
						ans += 1;
						dfs(i, j, curr);
					}
				}
			}
			printf("%d ", ans);			
		}

		printf("\n");
	}

    return 0;
}