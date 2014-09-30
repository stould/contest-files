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

const int MAXN = 5010;
const Int INF = 1001001010100101001LL;

int N, M;
Int MOD;
string S[MAXN];
int r1, r2, c1, c2;
char d;

Int dist[MAXN][MAXN][4];
Int seen[MAXN][MAXN][4];

int nei[4][2];

map<char, int> id;

int dx[4] = { 0, 0, -1, 1};
int dy[4] = {-1, 1,  0, 0};

void build(void) {
	id['N'] = 2; 
	id['S'] = 3;
	id['E'] = 1;
	id['W'] = 0;
	
	nei[0][0] = 2;
	nei[0][1] = 3;

	nei[1][0] = 2;
	nei[1][1] = 3;
	
	nei[2][0] = 0;
	nei[2][1] = 1;

	nei[3][0] = 0;
	nei[3][1] = 1;		
}

int main(void) {
	build();

	int t = 1;

	for ( ; cin >> N >> M >> MOD; ) {
		if (N == 0 && M == 0 && MOD == 0) break;

		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}
		cin >> r1 >> c1 >> r2 >> c2 >> d;		
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < 4; k++) {
					dist[i][j][k] = INF;
					seen[i][j][k] = 0LL;
				}
			}
		}
		
		queue<pair<int, pair<int, int> > > q;
		q.push(make_pair(id[d], make_pair(r1, c1)));
		
		dist[r1][c1][id[d]] = 0LL;
		seen[r1][c1][id[d]] = 1LL;

		Int best = INF;
		Int ans = 0LL;
		
		for ( ; !q.empty(); ) {
			int side = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			
			q.pop();

			if (x == r2 && y == c2) {
				best = dist[x][y][side];
				break;
			}
			
			//Forward
			int nx = x + dx[side];
			int ny = y + dy[side];
			
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && S[nx][ny] == '.') {	
				if (dist[nx][ny][side] > dist[x][y][side] + 1) {
					dist[nx][ny][side] = dist[x][y][side] + 1;
					
					seen[nx][ny][side] += seen[x][y][side];
					
					if (seen[nx][ny][side] >= MOD) {
						seen[nx][ny][side] -= MOD;
					}
					q.push(make_pair(side, make_pair(nx, ny)));
				} else if (dist[nx][ny][side] == dist[x][y][side] + 1) {
					seen[nx][ny][side] += seen[x][y][side];
					
					if (seen[nx][ny][side] >= MOD) {
						seen[nx][ny][side] -= MOD;
					}
				}
			}	

			for (int i = 0; i < 2; i++) {
				int nd = nei[side][i];
				if (dist[x][y][nd] > dist[x][y][side] + 1) {
					dist[x][y][nd] = dist[x][y][side] + 1;
					
					seen[x][y][nd] += seen[x][y][side];
					
					if (seen[x][y][nd] >= MOD) {
						seen[x][y][nd] -= MOD;
					}
					q.push(make_pair(nd, make_pair(x, y)));
				} else if (dist[x][y][nd] == dist[x][y][side] + 1) {
					seen[x][y][nd] += seen[x][y][side];
					
					if (seen[x][y][nd] >= MOD) {
						seen[x][y][nd] -= MOD;
					}
				}
			}			
		}
		

		for (int i = 0; i < 4; i++) {
			if (dist[r2][c2][i] == best) {
				ans = (ans + seen[r2][c2][i]) % MOD;
			}
		}
		
		if (best == INF) ans = -1;
		
		cout << "Case " << t++ << ": " << MOD << " " << ans << "\n";
	}
    return 0;
}
