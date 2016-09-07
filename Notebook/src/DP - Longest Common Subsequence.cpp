//Longest Commom Subsequence - (LCS) O(N^2)
int lcs(string a, string b) {
	int n = a.size(), m = b.size();
	int[][] dp = new dp[n+1][m+1];

	for(int i = 0; i <= max(n, m); i++) {
		dp[i][0] = dp[0][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}
