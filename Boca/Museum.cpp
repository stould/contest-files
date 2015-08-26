#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

int N, M;
int P[MAXN][MAXN];
int vis[MAXN][MAXN];

int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

int main() {
  while (cin >> M >> N) {
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	cin >> P[i][j];
      }
    }
    
    int ans = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	if (!vis[i][j] && P[i][j] == 1) {

	  queue<pair<int, int> > q;
	  q.push(make_pair(i, j));
	  vis[i][j] = 1;

	  while (!q.empty()) {
	    int ni = q.front().first;
	    int nj = q.front().second;
	    q.pop();
	    
	    for (int x = 0; x < 4; x++) {
	      int ai = ni + dx[x];
	      int aj = nj + dy[x];


	      if (ai >= 0 && aj >= 0 && ai < N && aj < M) {
		//cout << ni << " " << nj << " => " << ai << " " << aj << " - " << P[ai][aj] << " - " << vis[ai][aj] << "\n";
		if (P[ai][aj] == 1 && !vis[ai][aj]) {
		  q.push(make_pair(ai, aj));
		  vis[ai][aj] = 1;
		}
	      }
	    }
	  }
	  ans += 1;
	}
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
