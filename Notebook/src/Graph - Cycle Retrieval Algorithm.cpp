//It only works in graphs without compound cycles
bool inq[MAXN], vis[MAXN];

void dfs(int node, int parent, int len) {
	vis[node] = true;
	cle[node] = len;
	
	stk[stk_pointer++] = node;
	inq[node] = true;

	for (int i = 0; i < (int) graph[node].size(); i++) {
		int next = graph[node][i].first;
		int cost = graph[node][i].second;
		
		if (next == parent) continue;
		
		if (!vis[next]) {
			dfs(next, node, len + cost);
		} else {
			if (inq[next]) {
				int curr;
				int real_len = len + cost - cle[next];
				
				while (stk_pointer > 0) {
					curr = stk[--stk_pointer];
					inq[curr] = false;
					cycle_len[curr] = real_len;
					if (curr == next) break;				
				}
			}
		}
	}

	if (inq[node]) {
		while (stk_pointer > 0) {
			inq[stk[stk_pointer-1]] = false;
			if (stk[stk_pointer-1] == node) {
				stk_pointer--;
				break;
			}
			stk_pointer--;
		}
	}
}

stk_pointer = 0;
dfs(1, -1, 0);		

