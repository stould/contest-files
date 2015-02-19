#include <bits/stdc++.h>

using namespace std;

class FIELDDiagrams {
public:
	long long countDiagrams(int);
};

long long dp[40][40];

long long func(int row, int used, int fieldOrder) {
	if (row == fieldOrder + 1) {
		return 1;
	} else {
		long long& ans = dp[row][used];
		
		if (ans == -1LL) {
			ans = 0;
			
			for (int i = used; i <= row; i++) {
				ans += func(row + 1, i, fieldOrder);
			}
			
		}
		
		return ans;
	}
}

long long FIELDDiagrams::countDiagrams(int fieldOrder) {
	memset(dp, -1, sizeof(dp));
	
	return func(1, 0, fieldOrder) - 1;
}

//Powered by [KawigiEdit] 2.0!
