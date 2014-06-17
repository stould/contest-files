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

int dx[4] = { 0, 0, -1, 1};
int dy[4] = {-1, 1,  0, 0};

int N, M, K;
int vis[MAXN][MAXN];
string S[MAXN];

int rx[256], ry[256];
int tx[256];

char inv(char c) {
	if (c == 'x') {
		return c;
	} else if (c == '^') {
		return 'v';
	} else if (c == 'v') {
		return '^';
	} else if (c == '<') {
		return '>';
	} else {
		return '<';
	}
}

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return vis[a.first][a.second] > vis[b.first][b.second];
	}
};

bool bfs(int x, int y) {
	memset(vis, 63, sizeof(vis));
	vis[x][y] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > q;
	q.push(make_pair(x, y));

	rx['^'] = tx['v'] = 2; 
	rx['v'] = tx['^'] = 3;
	rx['<'] = tx['>'] = 0;
	rx['>'] = tx['<'] = 1;	
	
	for ( ; !q.empty(); ) {
		int nx = q.top().first;
		int ny = q.top().second;
		q.pop();
		
		if ((nx == 0 || ny == 0 || nx == N - 1 || ny == M - 1) && vis[nx][ny] <= K) {
			return true;			
		}		

		for (int i = 0; i < 4; i++) {
			int px = nx + dx[i];
			int py = ny + dy[i];
			
			int d = 0;

			if (px < 0 || py < 0 || px >= N || py >= M) {
					continue;
			}				

			if (rx[S[px][py]] == i) {
				d = 0;
			} else if (tx[S[px][py]] == i) {
				d = 1;
			} else {
				continue;
			}
			if (vis[px][py] > vis[nx][ny] + d) {
				vis[px][py] = vis[nx][ny] + d;
				q.push(make_pair(px, py));
			}
		}
	}		

	return false;
}

int main(void) {
	for ( ; cin >> N >> M >> K && N + M + K != 0; ) {
		int sx = -1, sy = -1;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			for (int j = 0; j < M; j++) {
				S[i][j] = inv(S[i][j]);
				if (S[i][j] == 'x') {
					sx = i, sy = j;
				}
			}
		}
		if (bfs(sx, sy)) {
			cout << "Sim\n";
		} else {
			cout << "Nao\n";
		}
	}
    return 0;
}
