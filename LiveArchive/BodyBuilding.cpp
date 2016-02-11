#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int T, N, M;
vector<int> graph[MAXN];
bool conn[MAXN][MAXN];
bool vis[MAXN][2];
int degree[MAXN];

bool dfs(int x, int p, int deg, int oppo, int parent) {
	vis[x][p] = true;

	if (deg != degree[x]) {
		return false;
	}
  
	for (int i = 0; i < (int) graph[x].size(); i++) {
		int u = graph[x][i];
    
		if (u == oppo || u == parent) continue;
		if (vis[u][p ^ 1]) return false;
    
		if (!vis[u][p]) {
			//      cout << "seen " << x << " " << u << "\n";
			if (!dfs(u, p, deg, oppo, x)) {
				//cout << x << " " << u << "\n";
				return false;
			}
		}
	}
  
	return true;
}

int main() {
	cin >> T;
  
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();

			memset(conn[i], false, sizeof(conn[i]));
			degree[i] = 0;
		}
    
		int A, B;

		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			graph[A].push_back(B);
			graph[B].push_back(A);
      
			conn[A][B] = conn[B][A] = true;
			degree[A] += 1;
			degree[B] += 1;
		}

		int ans = 0;
    
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (conn[i][j] && graph[i].size() == graph[j].size()) {	  
					memset(vis, false, sizeof(vis));

					degree[i] -= 1;
					degree[j] -= 1;

					bool va = dfs(i, 0, degree[i], j, -1);
					bool vb = dfs(j, 1, degree[j], i, -1);
	  
					degree[i] += 1;
					degree[j] += 1;
	  
					if (va && vb) {
						//cout << i << " " << j << "\n";
						ans += 1;
					}
				}
			}
		}
    
		cout << "Case #" << t << ": " << ans << "\n";
	}

	return 0;
}
