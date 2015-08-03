#include <bits/stdc++.h>
     
using namespace std;
     
const int MAXN = 1010;
const int INF = 1000101000;
     
int N;
int P[MAXN][MAXN];
pair<int, int> C[MAXN][MAXN];
pair<int, int> dp[MAXN][MAXN];
     
pair<int, int> countZ(int x) {
	if (x == 0) return make_pair(0, 0);
    	
	int c2 = 0;
	int c5 = 0;
    	
	while (x % 2 == 0) {
		c2 += 1;
		x /= 2;
	}

	while (x % 5 == 0) {
		c5 += 1;
		x /= 5;
	}
    	
	return make_pair(c2, c5);
}
     
pair<int, int> func(int r, int c) {
	if (r == N - 1 && c == N - 1) {
		return C[r][c];
	} else {
		pair<int, int>& ans = dp[r][c];
    		
		if (ans.first == -1) {
			ans.first = ans.second = INF;
    			
			if (r + 1 < N && P[r + 1][c] != 0) {
				pair<int, int> nx = func(r + 1, c);
    				
				nx.first += C[r][c].first;
				nx.second += C[r][c].second;
    				
				/*if (min(nx.first, nx.second) <= min(ans.first, ans.second)) {
				  ans = nx;
				  }
				*/
				if (nx.first < ans.first) {
					ans.first = nx.first;
				}
				if (nx.second < ans.second) {
					ans.second = nx.second;
				}
			}
			if (c + 1 < N && P[r][c + 1] != 0) {
				pair<int, int> nx = func(r, c + 1);
    				
				nx.first += C[r][c].first;
				nx.second += C[r][c].second;
    				
				if (nx.first < ans.first) {
					ans.first = nx.first;
				}
				if (nx.second < ans.second) {
					ans.second = nx.second;
				}
				/*				if (min(nx.first, nx.second) <= min(ans.first, ans.second)) {
								ans = nx;
								}
				*/
			}
		}
    		
		return ans;
	}
}
     
int main() {
	cin >> N;
    	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> P[i][j];
			C[i][j] = countZ(P[i][j]);
			dp[i][j].first = dp[i][j].second = -1;
		}		
	}
     
	pair<int, int> ans = func(0, 0);	
     
	cout << min(ans.first, ans.second) << "\n";
    	
	return 0;
} 
