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

const int MAXN = 12;
const int INF = 1001000;

int N, P;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0,-1, 1};

int matrix[MAXN][MAXN][MAXN][MAXN], dist[MAXN][MAXN];

int bfs(int x, int y, int a, int b) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INF;
		}
	}
	dist[x][y] = 0;	

	for ( ; !q.empty(); ) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		if (xx == a && yy == b) {
			return dist[xx][yy];
		}

		for (int i = 0; i < 4; i++) {
			int ni = xx + dx[i];
			int nj = yy + dy[i];		


			if (ni >= 0 && nj >= 0 && ni < N && nj < N) {
				//				printf("pesq = %d %d - %d %d - %d %d\n", xx, yy, ni, nj, dist[ni][nj], matrix[xx][yy][ni][nj]);			
				if (dist[ni][nj] > dist[xx][yy] + 1 && matrix[xx][yy][ni][nj] == 1) {
					q.push(make_pair(ni, nj));
					dist[ni][nj] = dist[xx][yy] + 1;
				}
			}
		}
	}
	return INF;
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		int pos;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {
						matrix[i][j][k][l] = 0;
					}
				}
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 4; k++) {
					scanf("%d", &pos);
					int ni = i + dx[k];
					int nj = j + dy[k];
					
					if (ni >= 0 && nj >= 0 && ni < N && nj < N) {
						if (pos == 1) {
							matrix[i][j][ni][nj] = matrix[ni][nj][i][j] = pos;		
							printf("%d %d - %d %d\n", i, j, ni, nj);
						}
					}
				}
			}
		}
		scanf("%d", &P);
		for ( ; P--; ) {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);

			printf("%d %d %d %d\n", a, b, c, d);
			int ans = bfs(a, b, c, d);

			if (ans >= INF) {
				puts("Impossible");
			} else {
				printf("%d\n", ans);
			}
		}
	}
    return 0;
}
