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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
	
int N, M;
string S[MAXN];
int dist[MAXN][MAXN];

void bfs(int si, int sj) {
	queue<pair<int, int> > q;
	q.push(make_pair(si, sj));
	
	memset(dist, 63, sizeof(dist));

	dist[si][sj] = 0;

	for ( ; !q.empty(); ) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ni = now.first + dx[i];
			int nj = now.second + dy[i];

			if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
				if (S[ni][nj] != 'T') {
					if (dist[ni][nj] > dist[now.first][now.second] + 1) {
						dist[ni][nj] = dist[now.first][now.second] + 1;
						q.push(make_pair(ni, nj));
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	int si, sj, ei, ej;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == 'S') {
				si = i;
				sj = j;
			}
			if (S[i][j] == 'E') {
				ei = i;
				ej = j;
			}
		}
	}

	bfs(ei, ej);
	
	int real_d = dist[si][sj];

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] > '0' && S[i][j] <= '9') {
				if (dist[i][j] <= real_d) {
					ans += S[i][j] - '0';
				}
			}
		}
	}

	cout << ans << "\n";
	
	return 0;
}
