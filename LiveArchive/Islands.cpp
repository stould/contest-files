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
bool vis[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y, int curr) {
	vis[x][y] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	for ( ; !q.empty(); ) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		int k;
		
		for (k = 0; k < 4; k++) {
			int xx = px + dx[k];
			int yy = py + dy[k];
			
			if (xx >= 0 && yy >= 0 && xx < N && yy < M && !vis[xx][yy] && arr[xx][yy] > curr) {
				vis[xx][yy] = true;
				q.push(make_pair(xx, yy));
			}
		}
	}
}

int main(void) {
	Z = in();

	int curr;

	for ( ; Z--; ) {
		N = in();
		M = in();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = in();
			}
		}

		T = in();

		for (int x = 0; x < T; x++) {
			int ans = 0;

			curr = in();

			memset(vis, false, sizeof(vis));

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (arr[i][j] > curr && !vis[i][j]) {
						ans += 1;
						bfs(i, j, curr);
					}
				}
			}
			printf("%d ", ans);			
		}

		printf("\n");
	}

    return 0;
}
