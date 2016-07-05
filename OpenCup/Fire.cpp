#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX / 4;
const int MAXN = 1010;

int N, M;
string S[MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

vector<vector<int> > bfs(vector<pair<int, int> > s) {
	vector<vector<int> > dist(N, vector<int>(M, INF));

	queue<pair<int, int> > q;

	for (int i = 0; i < (int) s.size(); i++) {    
		q.push(make_pair(s[i].first, s[i].second));
		dist[s[i].first][s[i].second] = 0;
	}

	while (!q.empty()) {
		int pi = q.front().first;
		int pj = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int di = pi + dx[i];
			int dj = pj + dy[i];

			if (in(di, dj) && S[di][dj] != '#') {
				if (dist[di][dj] > dist[pi][pj] + 1) {
					dist[di][dj] = dist[pi][pj] + 1;
					q.push(make_pair(di, dj));
				}
			}
		}   
	}
  
	return dist;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
  

	vector<pair<int, int> > VJ, FJ;
  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == 'J') {
				VJ.push_back(make_pair(i, j));
			}
			if (S[i][j] == 'F') {
				FJ.push_back(make_pair(i, j));

			}
		}
	}

	vector<vector<int> > JD = bfs(VJ);
	vector<vector<int> > FD = bfs(FJ);
  
	int ans = INF;
  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || j == 0 || i == N - 1 || j == M - 1) {
				if (JD[i][j] < FD[i][j]) {
					ans = min(ans, JD[i][j] + 1);
				}
			}
		}
	}

	if (ans == INF){
		cout << "IMPOSSIBLE\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
