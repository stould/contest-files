#include <bits/stdc++.h>

using namespace std;

int N, X0, Y0, X1, Y1;
int id = 1;
map<pair<int, int>, int> inv;
map<pair<int, int>, int> dist;

int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

void ins(int r, int c) {
	pair<int, int> s = make_pair(r, c);

	if (inv[s] == 0) {
		inv[s] = id++;
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> X0 >> Y0 >> X1 >> Y1;
	cin >> N;

	if (X1 < X0) {
		swap(X0, X1);
		swap(Y0, Y1);
	}

	for (int i = 0; i < N; i++) {
		int RW, L, R;
		cin >> RW >> L >> R;
    
		for (int j = L; j <= R; j++) {
			ins(RW, j);
		}
	}

	int ans = -1;

	queue<pair<int, int> > q;
	q.push(make_pair(X0, Y0));
 
	for ( ; !q.empty(); ) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int di = now.first + dx[i];
			int dj = now.second + dy[i];

			pair<int, int> as_pair = make_pair(di, dj);

			if (inv[as_pair] != 0) {
				if (dist[as_pair] == 0 || dist[as_pair] > dist[now] + 1) {
					dist[as_pair] = dist[now] + 1;
					q.push(as_pair);
				}
			}
		}
	}

	ans = dist[make_pair(X1, Y1)];

	if (ans == 0) {
		ans = -1;
	}

	cout << ans << "\n";
  
	return 0;
}
