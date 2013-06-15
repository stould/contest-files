#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int T, N, M, a, b, c, dist[110];
vector<pair<int, int> > graph[110];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

int dijsktra(int source, int destiny) {
	for(int i = 0; i <= 110; i++) {
		dist[i] = INT_MAX;
	}
	priority_queue<int, vector<int>, MyLess> q;
	dist[source] = 0;
 	q.push(source);

	while(!q.empty()) {
		int tmp = q.top(); q.pop();
		for(int i = 0; i < graph[tmp].size(); i++) {
            int aux_dist = dist[tmp] + graph[tmp][i].second;
            int actual_dist = dist[graph[tmp][i].first];
            if(aux_dist < actual_dist) {
                dist[graph[tmp][i].first] = aux_dist;
                q.push(graph[tmp][i].first);
            }
        }
    }
	return dist[destiny];
}

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> T;
    while(T--) {
        cin >> N >> M;
        REP(i, N) graph[i].clear();
        for(int i = 0; i < M; i++) {
            cin >> a >> b >> c; a -= 1; b -= 1;
            graph[a].push_back(make_pair(b, c));
            graph[b].push_back(make_pair(a, c));
        }
        REP(i, N) {
            printf("%d\n", dijsktra(i, i));
        }
        printf("\n");
    }
    return 0;
}
