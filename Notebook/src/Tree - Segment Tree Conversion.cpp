void dfs(int node, int p) {
    ini[node] = cnt++;
    for (int i = 0; i < (int) graph[node].size(); i++) {
        int next = graph[node][i];
        if (next != p) {			
            dfs(next, node);
        }
    }
}

int A, B;

for (int i = 0; i < N - 1; i++) {
    scanf("%d%d", &A, &B);
    graph[A].push_back(B);
    graph[B].push_back(A);
 }

cnt = 0;
dfs(0, -1);

for (int i = 0; i < Q; i++) {
    scanf("%d%d", &A, &B);
    
    if (A == 0) {
        update(1, 0, N - 1, ini[B], fin[B]);
    } else {
        printf("%d\n", query(1, 0, N - 1, ini[B], fin[B]));
    }
 }
