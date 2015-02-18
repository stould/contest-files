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

const int MAXN = 505;

int N, M;
char S[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

pair<int, pair<int, int> > bfs(int x, int y) {
	queue<pair<int, int> > q;
	int dist[MAXN][MAXN];

	memset(dist, -1, sizeof(dist));
	q.push(make_pair(x, y));
	dist[x][y] = 0;

	int best = -1;

	for ( ; !q.empty(); ) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		if (dist[xx][yy] > best) {
			best = dist[xx][yy];
			x = xx;
			y = yy;
		}
		

		for (int i = 0; i < 4; i++) {
			int ax = xx + dx[i];
			int ay = yy + dy[i];

			if (ax >= 0 && ax < N && ay >= 0 && ay < M && S[ax][ay] == '.') {
				if (dist[ax][ay] == -1 || dist[ax][ay] > dist[xx][yy] + 1) {
					q.push(make_pair(ax, ay));
					dist[ax][ay] = dist[xx][yy] + 1;
				}
			}
		}
	}
	return make_pair(best, make_pair(x, y));
}

int diameter(int x, int y) {
	pair<int, pair<int, int> > one = bfs(x, y);
	pair<int, pair<int, int> > two = bfs(one.second.first, one.second.second);
	return two.first;	
}

int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%s", S[i]);
		}
		int ans = -1;

		for (int i = 0; ans == -1 && i < N; i++) {
			for (int j = 0; ans == -1 && j < M; j++) {
				if (S[i][j] == '.') {
					ans = diameter(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
