void cost(int k, int l, int r, int optL, int optR) {
    if (l > r) return;
    
    int m = (l + r) / 2;
    
    Int best = INF;
    int id = optL;
    
    for (int i = optL; i <= min(m, optR); i++) {
        Int now = dp[i][k - 1] + cost(i + 1, m);
        
        if (now < best) {
            best = now;
            id = i;
        }
    }
    
    dp[m][k] = best;
    
    cost(k, l, m - 1, optL, id);
    cost(k, m + 1, r, id, optR);
}

for (int i = 1; i <= N; i++) {        
    dp[i][0] = cost(1, i);
 }

for (int i = 1; i <= M; i++) {
    cost(i, 1, N, 1, N);
 }
