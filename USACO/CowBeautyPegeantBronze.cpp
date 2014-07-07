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
const int INF = INT_MAX / 3;

int N, M;
char S[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int id) {
	if (x < 0 || y < 0 || x >= N || y >= M || vis[x][y] || S[x][y] != 'X') {
		return;
	}

	vis[x][y] = true;
	S[x][y] = (char) ('0' + id);

	dfs(x + 1, y, id);
	dfs(x - 1, y, id);
	dfs(x, y + 1, id);
	dfs(x, y - 1, id);
}

int bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	q.push(y);

	memset(dist, 63, sizeof(dist));
	dist[x][y] = 0;

	for ( ; !q.empty(); ) {
		int px = q.front(); q.pop();
		int py = q.front(); q.pop();

		if (S[px][py] == '2') {
			return dist[px][py];
		}

		for (int i = 0; i < 4; i++) {
			int qx = px + dx[i];
			int qy = py + dy[i];

			if (qx >= 0 && qy >= 0 && qx < N && qy < M && dist[qx][qy] > dist[px][py] + 1) {
				dist[qx][qy] = dist[px][py] + 1;
				q.push(qx);
				q.push(qy);
			}
				
		}
	}
}

void bfs_mark(int x, int y) {
	queue<int> q;
	q.push(x);
	q.push(y);

	memset(dist, 63, sizeof(dist));
	dist[x][y] = 0;
	
	pair<int, int>  pr[MAXN][MAXN];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pr[i][j] = make_pair(-1, -1);
		}
	}

	for ( ; !q.empty(); ) {
		int px = q.front(); q.pop();
		int py = q.front(); q.pop();

		if (S[px][py] == '2') {
			pair<int, int> curr = pr[px][py];

			while (1) {
				int p = curr.first;
				int q = curr.second;
				S[p][q] = 'X';
				curr = pr[p][q];
				if (curr.first == -1) {
					S[p][q] = '1';
					break;
				}
			}
			return;
		}

		for (int i = 0; i < 4; i++) {
			int qx = px + dx[i];
			int qy = py + dy[i];

			if (qx >= 0 && qy >= 0 && qx < N && qy < M && dist[qx][qy] > dist[px][py] + 1) {
				dist[qx][qy] = dist[px][py] + 1;
				pr[qx][qy] = make_pair(px, py);
				q.push(qx);
				q.push(qy);
			}
				
		}
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", S[i]);
	}

	int id = 1, len = INF, px = -1, py = -1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vis[i][j] && S[i][j] == 'X') {
				dfs(i, j, id++);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == '1') {
				int curr_len = bfs(i, j);

				if (curr_len < len) {
					len = curr_len;
					px = i;
					py = j;
				}
			}
		}
	}

	bfs_mark(px, py);

	for (int i = 0; i < N; i++) {
		printf("%s\n", S[i]);
	}

    return 0;
}
