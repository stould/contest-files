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

const int MAXN = 102;

int T, N, M;
string S[MAXN];
int vis[MAXN][MAXN][MAXN * MAXN];

int dx[4] = { 0, 0, -1, 1};
int dy[4] = {-1, 1,  0, 0};

map<char, int> opposite;
string dir = "^>v<";

//check curr pos of laser after s rotations[0, 4)
char now(char c, int s) {
	int pos = dir.find(c);
	return dir[(pos + s) % 4];
}

int main(void) {
	opposite['<'] = 1;
	opposite['>'] = 0;
	opposite['^'] = 3;
	opposite['v'] = 2;
	
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		int si = -1, sj = -1;
		int ei = -1, ej = -1;
		
		for (int i = 0; i < N; i++) {
			cin >> S[i];

			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'S') {
					si = i;
					sj = j;
					S[i][j] = '.';
				} else if (S[i][j] == 'G') {
					ei = i;
					ej = j;
					S[i][j] = '.';
				}
				
			}
		}

		int ans = INT_MAX;

		queue<pair<int, pair<int, int> > > q;
		q.push(make_pair(0, make_pair(si, sj)));

		memset(vis, 62, sizeof(vis));

		vis[si][sj][0] = 0;

		for ( ; !q.empty(); ) {
			int len = q.front().first;
			int ci = q.front().second.first;
			int cj = q.front().second.second;

			q.pop();

			bool ok = true;

			for (int i = 0; i < 4; i++) {
				for (int j = 1; ; j++) {
					int fi = ci + dx[i] * j;
					int fj = cj + dy[i] * j;

					if (fi < 0 || fj < 0 || fi >= N || fj >= M || S[fi][fj] == '#') {
						break;
					}

					if (S[fi][fj] != '.') {
						char op = now(S[fi][fj], len % 4);
						
						if (opposite[op] == i) {
							ok = false;
						}
					}
				}
			}
			
			if (!ok) continue;

			if (ci == ei && cj == ej) {
				ans = vis[ci][cj][len];
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ni = ci + dx[i];
				int nj = cj + dy[i];
				int nl = (len + 1) % 4;

				if (ni < 0 || nj < 0 || ni >= N || nj >= M || S[ni][nj] != '.') {
					continue;
				}

				if (vis[ni][nj][nl] > vis[ci][cj][len] + 1) {
					vis[ni][nj][nl] = vis[ci][cj][len] + 1;
					q.push(make_pair(nl, make_pair(ni, nj)));
				}
			}
		}

		cout << "Case #" << t << ": ";

		if (ans == INT_MAX) {
			cout << "impossible\n";
		} else {
			cout << ans << "\n";
		}
	}
	
    return 0;
}
