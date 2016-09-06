vector <pair<int, int> > edges;
int graph[MAXN][MAXN]; 
int dist[MAXN];

int N; 
bool bellman_ford(int s) {
	int M = edges.size();
	memset (dist, INF, sizeof(int)*n);
	dist[s] = 0;
	for (int k = 0; k < N-1; ++k) {
		for (int j = 0; j < M; ++j) {
			int u = edges[j].first;
			int v = edges[j].second;
			if (dist[u] < INF && dist[v] > dist[u] + graph[u][v])
				dist[v] = dist[u] + graph[u][v];
		}
	}
	//Negative Cycle
	for (int j = 0; j < m; ++j) {
		int u = edges[j].first, v = edges[j].second;
		if (dist[u] < INF && dist[v] > dist[u] + graph[u][v]) {
			return false;
		}
	}
	return true;
}
