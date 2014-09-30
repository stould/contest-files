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

const int MAXN = 1010;
const int INF = INT_MAX / 3;

int N, M;
Int  MOD;
string S[MAXN];
int r1, r2, c1, c2;
char d;

Int dist[MAXN][MAXN][4];
Int seen[MAXN][MAXN][4];

int change[5][5];

map<char, int> id;

int dx[4] = { 0, 0, -1, 1};
int dy[4] = {-1, 1,  0, 0};

void build(void) {
	id['N'] = 2; 
	id['S'] = 3;
	id['E'] = 1;
	id['W'] = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				change[i][j] = 1;
			} else {
				change[i][j] = 2;
			}
		}
	}
	
	change[2][3] = change[3][2] = 3;
	change[0][1] = change[1][0] = 3;
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
		
		memset(dist, 63, sizeof(dist));
		memset(seen,  0, sizeof(seen));
		queue<pair<int, pair<int, int> > > q;
		q.push(make_pair(id[d], make_pair(r1, c1)));

		dist[r1][c1][id[d]] = 1LL;
		seen[r1][c1][id[d]] = 1LL;
		
		for ( ; !q.empty(); ) {
			int side = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;

			q.pop();

			//			printf("%d %d - %d => %d %d\n", x, y, side, dist[x][y][side], seen[x][y][side]);

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx >= 0 && ny >= 0 && nx < N && ny < M && S[nx][ny] == '.') {
					int cst = change[side][i];
					
					if (dist[nx][ny][i] > dist[x][y][side] + cst) {
						dist[nx][ny][i] = dist[x][y][side] + cst;
						q.push(make_pair(i, make_pair(nx, ny)));

						seen[nx][ny][i] = seen[x][y][side] % MOD;

						if (cst == 3) {
							seen[nx][ny][i] += 1;							
						}						
						seen[nx][ny][i] %= MOD;
					} else if (dist[nx][ny][i] == dist[x][y][side] + cst) {
						seen[nx][ny][i] = ((seen[nx][ny][i] % MOD) + (seen[x][y][side] % MOD)) % MOD;
					}
				}				
			}
		}
		
		Int best = INF;
		Int ans = 0LL;

		for (int i = 0; i < 4; i++) {
			chmin(best, dist[r2][c2][i]);
		}

		//		cout << best << "\n";

		for (int i = 0; i < 4; i++) {
			if (dist[r2][c2][i] == best) {
				ans = (ans + seen[r2][c2][i]) % MOD;
			}
		}
		
		if (ans == 0) ans = -1;
		
		cout << "Case " << t++ << ": " << MOD << " " << ans % MOD << "\n";
	}
    return 0;
}
