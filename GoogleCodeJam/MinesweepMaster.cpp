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

int dx[8] = { 0, 1, 1,  1, 0, -1, -1, -1};
int dy[8] = {-1,-1, 0,  1, 1,  1,  0, -1};

int T, R, C, M;
char maze[60][60];
bool vis[60][60];

bool bfs(int x, int y) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if ((R * i + j) % 2 != 0) {
				maze[i][j] = '.';
			} else {
				maze[i][j] = '*';
			}
			vis[i][j] = false;
		}
	}

	maze[x][y] = 'c';
	vis[x][y] = true;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	int cnt = 1, goal = R * C - M;
	int par = 0;

	for ( ;!q.empty(); ) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		if (cnt == goal) continue;

		int pos = 0;
		for (int i = 0; i < 8; i++) {
			int ii = xx + dx[i];
			int jj = yy + dy[i];

			if (ii >= 0 && ii < R && jj >= 0 && jj < C) {
				if (!vis[ii][jj] && maze[ii][jj] == '*') {
					pos += 1;
				}
			}
		}
		if (cnt + pos > goal) continue;
		for (int i = 0; i < 8; i++) {
			int ii = xx + dx[i];
			int jj = yy + dy[i];

			if (ii >= 0 && ii < R && jj >= 0 && jj < C) {
				if (!vis[ii][jj] && cnt < goal) {
					vis[ii][jj] = true;
					maze[ii][jj] = '.';
					cnt += 1;
					q.push(make_pair(ii, jj));
				}
			}
		}
	}
	//	if (goal != cnt) return false;
	q = queue<pair<int, int> >();
	memset(vis, false, sizeof(vis));
	vis[x][y] = true;
	q.push(make_pair(x, y));

	bool end = true;

	for ( ; !q.empty(); ) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		int pos = 0, ok = 0;
		for (int i = 0; i < 8; i++) {
			int ii = xx + dx[i];
			int jj = yy + dy[i];

			if (ii >= 0 && ii < R && jj >= 0 && jj < C) {
				pos += 1;
			   	if (maze[ii][jj] == '.') ok += 1;
				vis[ii][jj] = true;
			}
		}
		if (pos == ok) {
			for (int i = 0; i < 8; i++) {
				int ii = xx + dx[i];
				int jj = yy + dy[i];

				if (ii >= 0 && ii < R && jj >= 0 && jj < C) {
					if (maze[ii][jj] == '.') {
						q.push(make_pair(ii, jj));
						vis[ii][jj] = true;
					}
				}
			}
		} else {
			if (maze[xx][yy] == 'c') {
				//				end = false;
			}
		}	 
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maze[i][j] == '.' || maze[i][j] == 'c') {
				if (!vis[i][j]) {
					//	end = false;
				}
			}
		}
	}
	return end;
}

int main(void) {
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> R >> C >> M;

		printf("Case #%d:\n", t);

		bool ans = bfs(0, 0);

		if (!ans) {
			printf("Impossible\n");
		} else {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					printf("%c", maze[i][j]);
				}
				puts("");
			}
		}
	}
    return 0;
}
