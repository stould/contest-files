#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

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


int x[110], y[110];

class KingdomXCitiesandVillagesAnother {
	public:
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY)  {
		int N = cityX.size(), M = villageX.size(), K = N + M;
		UnionFind u(K);
		vector<pair<double, pair<int, int> > > edges;
		for(int i = 0; i < N; i++) {
			x[i] = cityX[i];
			y[i] = cityY[i];
		}
		for(int i = 0; i < M; i++) {
			x[N+i] = villageX[i];
			y[N+i] = villageY[i];
		}
		for(int i = 0; i < N; i++) u.unite(0, i);
		
		for(int i = 0; i < K; i++) {
			for(int j = 0; j < i; j++) {
				edges.push_back(make_pair(hypot(x[i] - x[j], y[i] - y[j]), make_pair(i, j)));
			}
		}
		
		double sum = 0.0;
		sort(edges.begin(), edges.end());
		
		for(int i = 0; i < edges.size(); i++) {
			int ri = u.root(edges[i].second.first);
			int rj = u.root(edges[i].second.second);			
			if(ri == rj) continue;
			sum += edges[i].first;
			u.unite(edges[i].second.first, edges[i].second.second);
		}		
		return sum;
	}
};

// Powered by FileEdit
