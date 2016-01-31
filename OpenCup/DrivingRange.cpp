#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
int N, M;
int uf[MAXN];

int find(int x) {
	if (uf[x] == x) return x;
	return uf[x] = find(uf[x]);
}

void join(int a, int b) {
	uf[find(a)] = find(b);
}

int unite(int a, int b) {
	return find(a) == find(b);
}

int main() {
	while (cin >> N >> M && !(N == 0 && M == 0)) {
		vector<pair<int, pair<int, int> > > edge;

		for (int i = 0; i <= N; i++) {
			uf[i] = i;
		}
    
		for (int i = 0; i < M; i++) {
			int A, B, C;
			cin >> A >> B >> C;

			edge.push_back(make_pair(C, make_pair(A, B)));
		}

		sort(edge.begin(), edge.end());

		int best = -1;
		int cnt = 0;
    
		for (int i = 0; i < M; i++) {
			int a = edge[i].second.first;
			int b = edge[i].second.second;

			if (!unite(a, b)) {
				join(a, b);
				cnt += 1;
				best = max(best, edge[i].first);
			}
		}

		if (cnt != N - 1) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << best << "\n";
		}
	}
	return 0;
}
