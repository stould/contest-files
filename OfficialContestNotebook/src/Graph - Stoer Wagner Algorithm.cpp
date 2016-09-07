//Global Min-Cut Stoer-Wager O(N^3)
int graph[MAXN][MAXN] //Matrix de Adjacencia do grafo.

int minCut(int n) {
    bool a[n];
    int v[n];
    int w[n];
    for(int i = 0; i < n; i++) v[i] = i;
    int best = INF;
    while(n > 1) {
        int maxj = 1;
        a[v[0]] = true;
        for(int i = 1; i < n; ++i) {
            a[v[i]] = false;
            w[i] = graph[v[0]][v[i]];
            if(w[i] > w[maxj]) {
                maxj = i;
            }
        }
        int prev= 0 ,buf = n;
        while(--buf) {
            a[v[maxj]]=true;
            if(buf == 1) {
                best = min(best, w[maxj]);
                for(int k = 0; k < n; k++) {
                    graph[v[k]][v[prev]]= (graph[v[prev]][v[k]] += graph[v[maxj]][v[k]]);
                }
                v[maxj] = v[--n];
            }
            prev = maxj;
            maxj = -1;
            for(int j = 1; j < n; ++j) {
                if(!a[v[j]]) {
                    w[j] += graph[v[prev]][v[j]];
                    if(maxj < 0 || w[j] > w[maxj]) {
                        maxj=j;
                    }
                }
            }
        }
    }
    return best;
}
