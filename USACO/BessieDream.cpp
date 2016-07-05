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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1010;
const int INF = INT_MAX / 4;

int N, M;
int P[MAXN][MAXN];
int dist[MAXN][MAXN][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void) {
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> P[i][j];
			dist[i][j][0] = dist[i][j][1] = INF;
		}
	}

	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(0, make_pair(0, 0)));

	dist[0][0][0] = 0;
	
	int ans = -1;
	bool reach = false;
	
	while (!q.empty()) {
		int smell = q.front().first;
		int xi = q.front().second.first;
		int xj = q.front().second.second;
		q.pop();
		
		//cout << xi << " " << xj << " => " << smell << "\n";
		
		if (xi == N - 1 && xj == M - 1) {
			reach = true;
		}
		
		for (int i = 0; i < 4; i++) {
			int yi = xi + dx[i];
			int yj = xj + dy[i];

			if (yi >= 0 && yj >= 0 && yi < N && yj < M) {
				if (P[yi][yj] == 1) {
					if (dist[yi][yj][smell] > dist[xi][xj][smell] + 1) {
						dist[yi][yj][smell] = dist[xi][xj][smell] + 1;
						q.push(make_pair(smell, make_pair(yi, yj)));
					}
				} else if (P[yi][yj] == 2) {
					if (dist[yi][yj][1] > dist[xi][xj][smell] + 1) {
						dist[yi][yj][1] = dist[xi][xj][smell] + 1;
						q.push(make_pair(1, make_pair(yi, yj)));
					}
				} else if (P[yi][yj] == 3) {
					if (smell == 1) {
						if (dist[yi][yj][smell] > dist[xi][xj][smell] + 1) {
							dist[yi][yj][smell] = dist[xi][xj][smell] + 1;
							q.push(make_pair(smell, make_pair(yi, yj)));
						}						
					}
				} else if (P[yi][yj] == 4) {
					int len = 1;
					
					while (yi >= 0 && yj >= 0 && yi < N && yj < M && P[yi][yj] == 4) {
						yi += dx[i];
						yj += dy[i];
						len += 1;
					}

					if (!(yi >= 0 && yj >= 0 && yi < N && yj < M)) {
						yi -= dx[i];
						yj -= dy[i];
						len -= 1;
					} else if (P[yi][yj] == 3 || P[yi][yj] == 0) {
						yi -= dx[i];
						yj -= dy[i];
						len -= 1;
					}
					
					if (P[yi][yj] == 1 || P[yi][yj] == 4) {
						if (dist[yi][yj][0] > dist[xi][xj][smell] + len) {
							dist[yi][yj][0] = dist[xi][xj][smell] + len;
							q.push(make_pair(0, make_pair(yi, yj)));
						}
					} else if (P[yi][yj] == 2) {
						if (dist[yi][yj][1] > dist[xi][xj][smell] + len) {
							dist[yi][yj][1] = dist[xi][xj][smell] + len;
							q.push(make_pair(1, make_pair(yi, yj)));
						}
					}
				}
			}			
		}
	}

	if (reach) {
		ans = min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);
	}
	
	cout << ans << "\n";
	
	return 0;
}
