#include <bits/stdc++.h>

using namespace std;

const int MAXN = 22;

int N, M;
string S[MAXN];
vector<pair<int, int> > ans;
bool vis[MAXN][MAXN];
map<pair<int, int>, int> id;
int cnt_id = 1;

bool in(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

void dfs(int i, int j, int curr) {
	if (!in(i, j) || vis[i][j] || S[i][j] == '.') return;
 
	vis[i][j] = true;

	if (S[i][j] == 'O') {   
		if (curr != id[make_pair(i, j)]) {     
			ans.push_back(make_pair(curr, id[make_pair(i, j)]));
		}
	}

	if (S[i][j] == '|') {
		dfs(i - 1, j, curr);
		dfs(i + 1, j, curr);
	} else if (S[i][j] == '-') {
		dfs(i, j - 1, curr);
		dfs(i, j + 1, curr);
	} else if (S[i][j] == '+') {
		dfs(i, j - 1, curr);
		dfs(i, j + 1, curr);
		dfs(i - 1, j, curr);
		dfs(i + 1, j, curr);   
	} else if (S[i][j] == 'O') {
		dfs(i, j - 1, id[make_pair(i, j)]);
		dfs(i, j + 1, id[make_pair(i, j)]);
		dfs(i - 1, j, id[make_pair(i, j)]);
		dfs(i + 1, j, id[make_pair(i, j)]);   
	}
}

int main() {
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
 
	cin >> N >> M;

	cin.ignore();
 
	for (int i = 0; i < N; i++) {
		getline(cin, S[i]);

		for (int j = 0; j < M; j++) {
			if (S[i][j] == 'O') {
				id[make_pair(i, j)] = cnt_id++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == 'O') {
				dfs(i, j, id[make_pair(i, j)]);
				goto end;
			}
		}
	}

 end:;

	cout << ans.size() + 1 << "\n";
 
	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
 
	return 0;
}
