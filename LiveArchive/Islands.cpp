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

const int MAXN = 9010;

int T, Z;
int N, M;

int arr[MAXN][MAXN];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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
    int unite(int p, int q) {
        int i = root(p);
        int j = root(q);

        if(i == j) return 0;

		if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
		
		return 1;
    }
};

int conv(int i, int j) {
	return i * M + j;
}

int main(void) {
	Z = in();

	for ( ; Z--; ) {
		N = in();
		M = in();

		vector<pair<int, pair<int, int> > > val;
		vector<pair<int, pair<int, int> > >::iterator it;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = in();
				val.push_back(make_pair(arr[i][j], make_pair(i, j)));
			}
		}

		sort(val.begin(), val.end());
		
		T = in();

		vector<int> h(T);

		for (int x = 0; x < T; x++) {
			cin >> h[x];
		}
		
		UnionFind uf(N * M);
		vector<int> ans;
		
		int biggest_reached = INT_MAX;
		int component = 0;

		for (int i = T - 1; i >= 0; i--) {			
			int curr_h = h[i];
			it = lower_bound(val.begin(), val.end(), make_pair(curr_h + 1, make_pair(0, 0)));
			//cout << curr_h << " " << it->first << "\n";
			//if (it != val.end() && it->first < curr_h) it++;
			for ( ; it != val.end() && it->first < biggest_reached; it++) {
				component += 1;
							
				for (int k = 0; k < 4; k++) {
					int pi = it->second.first  + dx[k];
					int pj = it->second.second + dy[k];
					
					if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
						if (arr[pi][pj] > curr_h) {
							if (uf.unite(conv(it->second.first, it->second.second), conv(pi, pj))) {
								component -= 1;
							}
						}
					}
				}
			}
			ans.push_back(component);
			biggest_reached = curr_h + 1;
		}
		
		for (int i = 0; i < T; i++) {
			printf("%d ", ans[T - i - 1]);
		}
		printf("\n");
	}

    return 0;
}
