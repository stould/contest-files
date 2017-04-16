bool dfs(int node, int c) {
    if(color[node] != 0) {
        if(color[node] == c) {
            return true;
        } else {
            return false;
        }
    }
    color[node] = c;
    for(int i = 1; i <= n; i++) 
		if(gr[node][i] == 1) {
			if(!dfs(i, -c)) {
				return false;
			}
        }
    }
    return true;
}
