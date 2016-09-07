//Kadane 2D
for (int i = 1; i <= N; i++) {
	for (int j = 1; j <= N; j++) {
		cin >> M[i][j];
	}
	for (int j = 1; j <= N; j++) {
		dp[i][j] = dp[i][j - 1] + M[i][j];
	}
 }

int ans = -INT_MAX / 3;
for (int i = 1; i <= N; i++) {
	for (int j = i; j <= N; j++) {
		int sum = 0;
		for (int k = 1; k <= N; k++) {
			sum += dp[k][j] - dp[k][i - 1];
			chmax(ans, sum);
			if (sum < 0) sum = 0;
		}
	}
 }
