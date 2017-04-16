//Catalan numbers with DP
void getCatalan(int n){
    int catalan[n+1];
    int MOD = 100000000;
    for (int i=0; i <= n; i++){
        if (i==0 || i==1){
            catalan[i] = 1;
        }else{
            int sum =0;
            int l, r;
            for (int k=1;k<=i;k++){
                l = catalan[k-1] % MOD;
                r = catalan[i-k] % MOD;
                sum = (sum + (l * r) % MOD) % MOD;
            }
            catalan[i] = sum;
        }
    }
}
//Preprocessing Fatorial numbers and Answer in O(1)
Int catalan(int N) {
	Int ans = fat[2 * N];
	Int p = ((fat[N] * fat[N + 1]) % MOD) % MOD;
	ans *= modpow(p, MOD - 2, MOD);
	
	ans = ((ans % MOD) + MOD) % MOD;
	
	return ans;
}
