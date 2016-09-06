void build() {
    int pw = 1; //2^pw
    int base = 2;
 
    for (int i = 0; i < N; i++) {
        dp[i][0] = P[i];
    }
  
    while (base <= N) {
        for (int i = 0; i + base / 2 - 1 < N; i++) {
            int before = base / 2;		
            dp[i][pw] = min(dp[i][pw - 1], dp[i + before][pw - 1]);
        }    
        pw += 1;
        base *= 2;
    }
}
 
int query(int l, int r) {
    int len = r - l + 1;
 
    if (len == 1) return dp[l][0];
  
    int ps = 1;
    int pw = 0;
	
    while (l + 2 * ps <= r) {
        ps *= 2;
        pw += 1;
    }
 
    int a = dp[l][pw];
    int b = dp[r - ps + 1][pw];
 
    return min(a, b);
}
