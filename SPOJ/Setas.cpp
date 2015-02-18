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

const int MAXN = 510;

int N;
string S[MAXN];
bool vis[MAXN][MAXN], safe[MAXN][MAXN];

map<char, int> dx, dy;

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	vis[x][y] = true;

	bool out = false;

	vector<pair<int, int> > memo;

	for ( ; !q.empty(); ) {
		int px = q.front().first;
		int py = q.front().second;
		memo.push_back(q.front());
		q.pop();

		int nx = px + dx[S[px][py]];
		int ny = py + dy[S[px][py]];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (!vis[nx][ny]) {
				q.push(make_pair(nx, ny));
				vis[nx][ny] = true;
			} else {
				out = safe[nx][ny];
			}
		} else {
			out = true;
			break;
		}
	}
	for (int i = 0; i < (int) memo.size(); i++) {
		safe[memo[i].first][memo[i].second] = out;
	}
}

int main(void) {
	dx['V'] = 1;
	dy['V'] = 0;
	dx['<'] = 0;
	dy['<'] = -1;
	dx['>'] = 0;
	dy['>'] = 1;
	dx['A'] = -1;
	dy['A'] = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	int ans = 0;
	memset(vis, false, sizeof(vis));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!safe[i][j]) {
				ans += 1;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
