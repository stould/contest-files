//ga -> Regular Adjacency List
//gb -> Transposed Adjacency List

void dfs1(int x) {
    used[x] = 1;
    for(int b = 0; b < g[x].size(); b++) {
        if(!used[g[x][b]]) dfs1(g[x][b]);
    }
	order.push_back(x);		
}

void dfs2(int x) {
    used[x] = 1;
	comoponent.insert(x);
    for(int b = 0; b < gr[x].size(); b++) {
        if(!used[gr[x][b]]) dfs2(gr[x][b]);
    }
}

//Topological Sort
for (int i = 1; i <= n; i++) if(!used[i]) dfs1(i);

//Get components
for(int i = 0; i < order.size(); i++) {
    int v = order[i];
	if(!used[v]) {
		dfs2(v);
        ans++;
        component.clear();
	}
}
