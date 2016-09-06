int meses[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int dp[8000][13][34];

for(int i = -3113; i <= 4000; i++){
	for(int j = 1; j <= 12; j++) {
		for(int k = 1; k <= meses[j] + (isLeap(i) && j == 2); k++){
			dp[i + 3113][j][k] = past++;
		}
	}
 }

