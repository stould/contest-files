//Menor string que contem duas strings S1 e S2 como subsequencia

char S1[MAXS], S2[MAXS];
int dp[MAXS][MAXS];

memset(dp, 0, sizeof(dp));

for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) {
        if (S1[i - 1] == S2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
           dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

string track(int i, int j) {
    if (i == 0 && j == 0) {
        return "";
    } else if (i == 0 && j > 0) {
        return track(i, j - 1) + S2[j - 1];
    } else if (i > 0 && j == 0) {
        return track(i - 1, j) + S1[i - 1];
    } else {
        if (S1[i - 1] == S2[j - 1]) {
            return track(i - 1, j - 1) + S1[i - 1];
        } else {
            if (dp[i][j - 1] > dp[i - 1][j]) {
                return track(i, j - 1) + S2[j - 1];
            } else {
                return track(i - 1, j) + S1[i - 1];
            }
        }
    }
}
