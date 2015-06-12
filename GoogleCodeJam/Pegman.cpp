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

const int MAXN = 110;

int T, R, C;
string S[MAXN];
bool vis[MAXN][MAXN];
bool over, fix;
map<char, int> dx;
map<char, int> dy;

char inv(char c) {
	if (c == '^') return 'v';
	else if (c == 'v') return '^';
	else if (c == '<') return '<';
	else return '<';
}

bool out(int x, int y) {
	return x < 0 || y < 0 || x >= R || y >= C;
}

void build(void) {
	dx['^'] = -1;
	dy['^'] =  0;

	dx['v'] = +1;
	dy['v'] =  0;

	dx['<'] =  0;
	dy['<'] = -1;

	dx['>'] =  0;
	dy['>'] = +1;
}

int dfs(int x, int y, char dir) {
	if (out(x, y)) {
		return 1;
	} else {
		int ni = x;
		int nj = y;
		
		ni += dx[dir];
		nj += dy[dir];

		if (!out(ni, nj) && S[ni][nj] != '.') return 0;	
		
		return dfs(ni, nj, dir);
	}
}

int main(void) {
	build();
	
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		
		cin >> R >> C;

		for (int i = 0; i < R; i++) {
			cin >> S[i];
		}
		
		int ans = 0;
		bool imp = false;
		over = false;
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (S[i][j] != '.') {
					int out = dfs(i, j, S[i][j]);

					if (out) {
						ans += 1;
						bool found = false;
						
						for (int k = i - 1; k >= 0; k--) {
							if (S[k][j] != '.') {
								S[i][j] = '^';
								found = true;
							}
						}
						for (int k = i + 1; k < R; k++) {
							if (S[k][j] != '.') {
								S[i][j] = 'v';
								found = true;
							}
						}
						for (int k = j - 1; k >= 0; k--) {
							if (S[i][k] != '.') {
								S[i][j] = '<';
								found = true;
							}
						}
						for (int k = j + 1; k < C; k++) {
							if (S[i][k] != '.') {
								S[i][j] = '>';
								found = true;
							}
						}												
						if (!found) imp = true;
					}
				}
			}
		}
		if (imp) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}
