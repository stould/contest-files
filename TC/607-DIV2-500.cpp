#include <bits/stdc++.h>

using namespace std;

class PalindromicSubstringsDiv2 {
public:
	int count(vector <string>, vector <string>);
};

int dp[5001][5001];

int func(string arg) {
	int N = (int) arg.size();
	
	memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i < N; i++) {
		dp[i][i] = 1;
		if (i + 1 < N && arg[i] == arg[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			dp[j][i + j] = dp[j + 1][i + j - 1] && (arg[j] == arg[i + j]);	
//			cout << j << " " << i << " "  << arg[j] << " " << arg[i + j] << " " << dp[i][i + j] << "\n";
		}
	}
	
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			ans += dp[i][j];
		}
	}
	
	return ans;
}

int PalindromicSubstringsDiv2::count(vector <string> S1, vector <string> S2) {
	string A = accumulate(S1.begin(), S1.end(), string(""));
	string B = accumulate(S2.begin(), S2.end(), string(""));
	
	string all = A + B;
	
	return func(all);
}

//Powered by [KawigiEdit] 2.0!
