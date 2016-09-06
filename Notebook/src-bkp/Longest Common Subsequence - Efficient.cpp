//Longest Commom Subsequence - (LCS) O(n^2) - O(n) in space
int m[2][1000]; // instead of [1000][1000]
for (i = M; i >= 0; i--) {
	int ii = i&1; 
	for (int j = N; j >= 0; j--) {
		if (i == M || j == N) {
			m[ii][j]=0; continue;
		}
		if (s1[i] == s2[j]) {
			m[ii][j] = 1 + m[1-ii][j+1];
		} else {
			m[ii][j] = max(m[ii][j+1], m[1-ii][j]);
		}
	}
 }
cout<<m[0][0];
