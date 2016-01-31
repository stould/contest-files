#include <bits/stdc++.h>

using namespace std;

const long long INF = 1001010010101000LL;

long long N, R, P;
long long dp[1000005];

long long func(int p) {
	if (p == 1) {
		return 0;
	} else {
		long long& ans = dp[p];

		if (ans == -1) {
			ans = INF;
      
			for (int i = 1; i <= p; i++) {
				long long curr = R + P * i + func((int) ceil(p / (double) (i + 1)));
				ans = min(ans, curr);
			}
		}
    
		return ans;
	}
}

int main() {
	cin >> N >> R >> P;
  
	memset(dp, -1, sizeof(dp));
  
	cout << func(N) << "\n";
  
	return 0;
}
