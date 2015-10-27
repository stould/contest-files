#include <bits/stdc++.h>
#define ll long long

#define MOD 1000000007LL

using namespace std;

const int MAXN = 1001;

ll dp[MAXN][MAXN];

int N, K;

ll func(int seen, int ones){
	if (seen == 0){
		return ones == 0;
	}else{
		ll &ans = dp[seen][ones];
		if(ans == -1){
			ans = 0;
			int zero = N - ones;
      
			if (ones > 0) {
				ans = (ans % MOD) + (ones * func(seen - 1, ones - 1)) % MOD;
			}
			ans %= MOD;
      
			if (zero > 0) {
				ans = (ans % MOD) + (zero * func(seen - 1, ones + 1)) % MOD;
			}
		}    
		ans = ((ans % MOD) + MOD) % MOD;
		return ans;
	}
}

int T, val;

int main() {
	cin >> T;
	for(int test = 1; test <= T; test++){
		cin >> N >> K;
		int ones = 0;
		for(int i = 0; i < N; i++){
			cin >> val;
			ones += val;      
		}
		memset(dp,-1,sizeof(dp));
		cout << "Case #" << test << ": " << func(K, ones) << endl;
	}
	return 0;

}

 
