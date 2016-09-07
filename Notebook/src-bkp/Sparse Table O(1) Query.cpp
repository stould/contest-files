int n, val[MAXN], pre[MAXN];
int dp[MAXN][LOGVAL];
void preProcess(){
    int base = 1;
    int pot = 0;
    for(int i = 0; i < MAXN; i++){
        if(i >= base * 2){
            pot++;
            base *= 2;
        }
        pre[i] = pot;
        dp[i][0] = i;
    }
    base = 2;
    pot = 1;
    while(base <= n){
        for(int i = 0; i + base / 2 - 1 < n; i++){
            int before = base / 2;
            if(val[dp[i][pot-1]] < val[dp[i + before][pot-1]]){
                dp[i][pot] = dp[i][pot-1];
            }else{
                dp[i][pot] = dp[i + before][pot-1];
            }
        }
        base *= 2;
        pot++;
    }
}
int query(int l, int r){
    int len = r-l+1;
    if(len == 1){
        return dp[r][0];
    }else{
        int base = (1 << pre[len]);
        int pot = pre[len];
        if(val[dp[l][pot]] < val[dp[r-base+1][pot]]){
            return dp[l][pot];
        }else{
            return dp[r-base+1][pot];
        }
    }
}

//0-based, dentro da main:
preProcess();
val[query(left, right)] //->should be the answer
