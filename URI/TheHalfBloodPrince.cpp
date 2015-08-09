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

int N, M;
vector<string> S;
int ans;
bool vis[5][5];
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

bool ok(vector<string>& arg) {
	int mask = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			mask |= (1 << (arg[i][j] - '0'));
		}
	}

	return __builtin_popcount(mask) == 1;
}

void back(vector<string>& vs, int cnt) {
	if (cnt >= ans) return;
	if (ok(vs)) {
		cout << cnt << endl;
		chmin(ans, cnt);
	} else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (vs[i][j] != vs[0][0]) {
					int seen = 0;
					vector<string> other = vs;
					memset(vis, false, sizeof(vis));
					
					stack<pair<int, int> > st;
					st.push(make_pair(0, 0));
					vis[0][0] = true;

					for ( ; !st.empty(); ) {
						int r = st.top().first;
						int c = st.top().second;
						st.pop();
						
						vis[r][c] = true;
						other[r][c] = vs[i][j];
						
						for (int p = 0; p < 4; p++) {
							int nr = r + dx[p];
							int nc = c + dy[p];
							
							if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
								if (!vis[nr][nc]) {
									if (vs[nr][nc] == vs[0][0] or vs[nr][nc] == vs[i][j]) {
										seen += 1;
										st.push(make_pair(nr, nc));
									}
								}
							}
						}
					}
					if (seen > 0) {
						back(other, cnt + 1);
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> N >> M;

	S.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	ans = INT_MAX;
	back(S, 0);

	cout << ans << endl;
	
	return 0;
}
