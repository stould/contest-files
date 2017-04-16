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
//Reconstrução do Caminho
vector<int> path;
int start = destiny;

while(start != -1) {
	path.push_back(start);
	start = prev[start];
}
