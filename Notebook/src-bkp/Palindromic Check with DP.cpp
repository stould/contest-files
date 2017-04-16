//Checa por Palindromos
int T, N, dp[MAXN][MAXN];
char str[MAXN];

for (int i = 0; i < N; i++) {
    dp[i][i] = 1;
    if(i + 1 < N) dp[i][i + 1] = str[i] == str[i + 1];
}
for(int k = 2; k < N; k++) {
    for (int i = 0; i < N - k; i++) {
        dp[i][i + k] = dp[i + 1][i + k - 1] && str[i] == str[i + k];
    }
}
