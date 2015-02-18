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

int dx[8] = { 0, 0, -1, 1, -1, 1, -1,  1};
int dy[8] = {-1, 1,  0, 0, -1, 1,  1, -1};

int T, N, M;
bool field[MAXN][MAXN];
bool vis[MAXN][MAXN];

int dfs(int x, int y) {	
	int ans = 0;

	stack<pair<int, int> > stk;
	stk.push(make_pair(x, y));

	for ( ; !stk.empty(); ) {
		x = stk.top().first;
		y = stk.top().second;
		stk.pop();

		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if (xx >= 0 && yy >= 0 && xx < N && yy < M && !vis[xx][yy] && field[xx][yy]) {
				ans += 1;
				vis[xx][yy] = true;
				stk.push(make_pair(xx, yy));
			}
		}
	}
	return ans;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> T;

	int troop = 0;
	int largest = 0;
	
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		int troop = 0;
		int largest = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> field[i][j];
				vis[i][j] = false;
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 1 && !vis[i][j]) {
					troop += 1;
					largest = max(largest, dfs(i, j));
				}
			}
		}
		cout << troop << " " << largest << "\n";
	}

    return 0;
}
