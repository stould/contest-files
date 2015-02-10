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

const int MAXN = 10004;
const int INF = INT_MAX / 3;

int N, M, Q;
vector<pair<int, int> > graph[MAXN];
int stk[MAXN], stk_pointer;
int cycle_len[MAXN];
int dist[MAXN];
bool vis[MAXN];

void dfs(int node, int parent, int len) {
	vis[node] = true;

	cout << node << "\n";
	//cout << node << " " << parent << " " << len << "\n";
	
	//stk[stk_pointer++] = node;
	
	for (int i = 0; i < (int) graph[node].size(); i++) {
		int next = graph[node][i].first;
		int cost = graph[node][i].second;
		
		if (next == parent) continue;

		if (!vis[next]) {
			dfs(next, node, len + cost);
		} else {
			continue;
			int curr;

			while (stk_pointer > 0) {
				curr = stk[stk_pointer--];
				//cout << curr << "\n";
				cycle_len[curr] = len;
				if (curr == next) break;
			}
			//cout << "\n";
		}
	}

	if (stk_pointer > 0) {
		stk_pointer--;
	}
}

void dijkstra(int node) {
	fill(dist, dist + N + 1, INF);

	dist[node] = 0;

	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, node));
	
	for ( ; !q.empty(); ) {
		int now = q.top().second;
		int now_dist = q.top().first;
		
		q.pop();
		
		if (now_dist > dist[now]) continue;

		for (int i = 0; i < (int) graph[now].size(); i++) {
			int next = graph[now][i].first;
			int cost = graph[now][i].second;

			if (dist[next] > dist[now] + cost) {
				dist[next] = dist[now] + cost;
				q.push(make_pair(-dist[next], next));
			}
		}
	}	
}

int main(void) {
	for ( ; scanf("%d%d", &N, &M); ) {
		for (int i = 0; i <= N; i++) {
			vis[i] = false;
			cycle_len[i] = -1;
			graph[i].clear();
		}
		
		for (int i = 0; i < M; i++) {
			int A, B, C;
			scanf("%d%d%d", &A, &B, &C);

			graph[A].push_back(make_pair(B, C));
			graph[B].push_back(make_pair(A, C));
		}
		
		for (int i = 1; i <= N; i++) {
			memset(vis, false, sizeof(vis));
			stk_pointer = 0;
			dfs(i, -1, 0);			
		}

		scanf("%d", &Q);

		for (int i = 0; i < Q; i++) {
			int V, L;
			scanf("%d%d", &V, &L);

			dijkstra(V);

			int ans = INT_MAX;

			for (int i = 0; i < V; i++) {
				if (cycle_len[i] != -1) {
					chmin(ans, 2 * dist[i] + cycle_len[i]);
				}
			}

			if (ans == INT_MAX) {
				ans = -1;
			}
			printf("%d\n", ans);		
		}
	}
	
    return 0;
}
