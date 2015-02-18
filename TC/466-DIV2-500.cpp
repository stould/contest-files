#include <bits/stdc++.h>

using namespace std;

class LotteryCheating {
public:
	int minimalChange(string);
};

const int INF = INT_MAX / 3;

int len(long long x) {
	int ans = 0;
	
	while (x > 0) {
		ans += 1;
		x /= 10;
	}
	
	return ans;
}

int LotteryCheating::minimalChange(string ID) {
	int ans = INF;
	int N = (int) ID.size();
	
	for (long long i = 0LL; len(i * i) <= N; i++) {
		long long x = i * i;
		
		string S = "";
		
		for (int j = 0; j < N; j++) {
			S += '0';
		}

		for (int j = N - 1; j >= 0; j--) {
			S[j] = '0' + (x % 10);
			x /= 10;
		}
		
		int cnt = 0;
		
	
		for (int j = 0; j < N; j++) {
			if (S[j] != ID[j]) {
				cnt += 1;
			}			
		}	
		ans = min(ans, cnt);	
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
