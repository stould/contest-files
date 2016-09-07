//Binomial Coefficient
//C(N, K) = N!/(K!(N - K)!)
//Dynamic Programming
int bin[N][K];

bin[0][0] = 1;

for (int n = 1; n < MAXN; n++) {
    bin[n][0] = 1;
    bin[n][n] = 1;
	
    for (int k = 1; k < n; k++) {
		bin[n][k] = bin[n - 1][k] + bin[n - 1][k - 1];
		if (bin[n][k] >= MOD) {
			bin[n][k] -= MOD;
		}
    }
 }
