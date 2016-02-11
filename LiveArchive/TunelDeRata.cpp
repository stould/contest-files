#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second > b.second;
}

struct UnionFind {
    int N, *id, *sz;

    UnionFind(int _N) {
        id = new int[_N];
        sz = new int[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        N = _N;
    }
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		vector<pair<pair<int, int>, int> > ve;

		int sum = 0;
		int best = 0;
    
		int A, B, C;
		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;     
			ve.push_back(make_pair(make_pair(A, B), C));
			sum += C;
		}

		sort(ve.begin(), ve.end(), cmp);
		UnionFind uf(N + 1);

		for (int i = 0; i < M; i++) {
			A = ve[i].first.first;
			B = ve[i].first.second;
			C = ve[i].second;

			if (!uf.find(A, B)) {
				uf.unite(A, B);
				sum -= C;
			} else {
				best = max(best, C);
			}
		}

		cout << "Case #" << t << ": " << sum << " " << best << "\n";
	}
	return 0;
}
