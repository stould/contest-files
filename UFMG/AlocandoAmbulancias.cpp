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

const int MAXN = 1010;

int N, M, Q;
int dist[MAXN];
vector<pair<int, int> > graph[MAXN];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

int dijkstra(int source) {
	int best = 0;
	
	for(int i = 0; i < MAXN; i++) {
		dist[i] = INT_MAX;
	}
	
	priority_queue<int, vector<int>, MyLess> q;
	dist[source] = 0;
 	q.push(source);

	while(!q.empty()) {
		int tmp = q.top(); q.pop();

		chmax(best, dist[tmp]);
		
		for(int i = 0; i < graph[tmp].size(); i++) {
            int aux_dist = dist[tmp] + graph[tmp][i].second;
            int actual_dist = dist[graph[tmp][i].first];
            if(aux_dist < actual_dist) {
                dist[graph[tmp][i].first] = aux_dist;
                q.push(graph[tmp][i].first);
            }
        }
    }
	return best;
}


int main(void) {
	for ( ; scanf("%d%d%d", &N, &M, &Q) == 3; ) {
		for (int i = 0; i <= N; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int A, B, C;
			scanf("%d%d%d", &A, &B, &C);
			graph[A].push_back(make_pair(B, C));
			graph[B].push_back(make_pair(A, C));
		}
		for (int i = 0; i < Q; i++) {
			int X;
			scanf("%d", &X);
			graph[0].push_back(make_pair(X, 0));
		}

		cout << dijkstra(0) << "\n";
	}
	
    return 0;
}
