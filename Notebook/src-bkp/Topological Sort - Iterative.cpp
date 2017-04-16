priority_queue<int, vector<int>, greater<int> > pq;
 
for (int i = 0; i < N; i++) {
	if(deg[i] == 0) {
		pq.push(i);
	}
 }
int on = 0;
while (!pq.empty()) {
	int now = pq.top(); 
	pq.pop();
	order.push_back(now);
	for (int i = 0; i < (int) graph[now].size(); i++) {
		int next = graph[now][i]; 
		deg[next] -= 1;
		
		if(deg[next] == 0) {
			pq.push(next);
		}
	}
 }
