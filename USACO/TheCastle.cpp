/*
  ID: jeferso1
  LANG: C++
  TASK: castle
*/

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

const int MAXN = 50;

int N, M;
int S[MAXN][MAXN], belong[MAXN][MAXN];
bool vis[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inside(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M;
}

bool can(int x, int y, int a, int b) {
	if (x - 1 == a) {
		return !(S[x][y] & 2);
	} else if (x + 1 == a) {
		return !(S[x][y] & 8);
	} else if (y + 1 == b) {
		return !(S[x][y] & 4);
	} else if (y - 1 == b) {
		return !(S[x][y] & 1);
	} else {
		return false;
	}
}

int bfs(int x, int y, int w) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	vis[x][y] = true;

	int ans = 0;
	
	for ( ; !q.empty(); ) {
		int ni = q.front().first;
		int nj = q.front().second;
		q.pop();

		ans += 1;
		
		belong[ni][nj] = w;

		for (int i = 0; i < 4; i++) {
			int di = ni + dx[i];
			int dj = nj + dy[i];

			if (inside(di, dj) && can(ni, nj, di, dj) && !vis[di][dj]) {
				vis[di][dj] = true;
				q.push(make_pair(di, dj));
			}
		}
	}

	return ans;
}

int main(void) {
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> S[i][j];
			belong[i][j] = -1;
		}
	}
	
	int cnt = 0;
	int best = 0;
	int sum = 0;
	int row = MAXN, col = MAXN;
	char pos = '$';
	
	vector<int> sz;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vis[i][j]) {
				sz.push_back(bfs(i, j, cnt++));

				if (best < sz.back()) {
					best = sz.back();
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int di = i + dx[k];
				int dj = j + dy[k];
				
				if (inside(di, dj) && !can(i, j, di, dj)) {
					//cout << i + 1 << " " << j + 1 << " " << di + 1 << " " << dj + 1 << " =  " << belong[i][j] << " " << belong[di][dj] << endl;
					if (belong[i][j] != belong[di][dj]) {
						if (sum < sz[belong[i][j]] + sz[belong[di][dj]]) {
							sum = sz[belong[i][j]] + sz[belong[di][dj]];
							
							row = i + 1;
							col = j + 1;
							
							if (k <= 1) {
								pos = 'E';
							} else {
								pos = 'N';
							}
						} else if (sum == sz[belong[i][j]] + sz[belong[di][dj]]) {
							if (j < col or (j == col && i > row)) {
								row = i + 1;
								col = j + 1;
								
								if (k <= 1) {
									pos = 'E';
								} else {
									pos = 'N';
								}
							} 
						}
					}
				}
			}
		}
	}
			

	cout << cnt << endl << best << endl << sum << endl << row << " " << col << " " << pos << endl;
			
	return 0;
}
