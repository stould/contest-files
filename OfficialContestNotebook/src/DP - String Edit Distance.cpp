int dist(string& s1, string& s2) {
    int N1 = s1.size(), N2 = s2.size();

    for (int i = 0; i <= N1; i++) dp[i][0] = i;
    for (int i = 0; i <= N2; i++) dp[0][i] = i;

    for (int i = 1; i <= N1; i++) {
		for (int j = 1; j <= N2; j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
			}
		}
	}
	return dp[N1][N2];
}
