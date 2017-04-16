//Coin Change
int dp[1001];
int coins[] = {1, 5, 10, 25, 50};

dp[0] = 0;

for(int i = 1; i <= N; i++) {
	int min = 1000001;
    for(int j = 0; j < M; j++) {
		if(coins[j] <= i) {
			int m = dp[i - coins[j]] + 1;
            if(m < min) min = m;
        }
    }
    dp[i] = min;
}
