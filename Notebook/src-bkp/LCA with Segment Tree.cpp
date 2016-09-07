//LCA using segment tree
int H[MAXN], L[MAXN << 1], E[MAXN << 1], vis[MAXN], tree[MAXN * 8], path[MAXN << 1];
vector<vector<pair<int, int> > > g(MAXN);

void dfs(int x, int depth){
	vis[x] = 1;//visited
	if(H[x] == -1) H[x] = idx;//mark first time the i'th node is visited
	L[idx] = depth;//when you visit a node you should mark the the depth you have found it.
	E[idx++] = x;//the i'th recursion, global variable
	for(int i = 0; i < g[x].size(); i++){
		int next = g[x][i].first;
		if(!vis[next]){
			path[next] = x;
			dfs(next, depth+1);
			L[idx] = depth;
			E[idx++] = x;
		}
	}
}

//NlogN build the segtree and minimize the height of the I'th visited node
void build(int node, int l, int r){
	if(l > r) return;
	if(l == r){
		tree[node] = l;
	}else{
		int mid = (l+r) >> 1;
		build(node*2, l, mid);
		build(node*2+1, mid+1, r);
		int A = tree[node*2];
		int B = tree[node*2+1];
		if(L[A] <= L[B]){
			tree[node] = A;
		}else{
			tree[node] = B;
		}
	}
}

//Get the vertex with the minimum height, then it will be the LCA of A and B.
int rmq(int node, int l, int r, int ra, int rb){
	if(l > rb || r < ra){
		return -1;
	}else if(l >= ra && r <= rb){
		return tree[node];
	}else{
		int mid = (l+r) >> 1;
		int q1 = rmq(node*2, l, mid, ra, rb);
		int q2 = rmq(node*2+1, mid+1, r, ra, rb);
		if(q1 == -1){
			return q2;
		}else if(q2 == -1){
			return q1;
		}else{
			if(L[q1] <= L[q2]){
				return q1;
			}else{
				return q2;
			}
		}
	}
}

idx = 0;
for(int i = 0; i <= n; i++){
	g[i].clear();
	H[i] = -1;
	L[i] = E[i] = vis[i] = 0;
	path[i] = -1;
 }
dfs(0,0);
build(1, 0, 2*n-1);
for(int i = 0; i < k; i++){
	scanf("%d%d", &u, &v);
	u--;
	v--;
	int goFrom = H[u];
	int goTo = H[v];
	if(goFrom > goTo){
		swap(goFrom, goTo);
	}
	int lcaAB = E[rmq(1, 0, 2*n-1, goFrom, goTo)]; //is the LCA of A and B;
 }

