#include <bits/stdc++.h>

using namespace std;

class ColorfulRoad {
public:
	int getMin(string);
};

const int MAXN = 20;
const int INF = 10101010;

int dp[MAXN][MAXN];

map<char, int> bf;

int func(int id, int prev, string road) {
	int i;
	int N = (int) road.size();
	
	if (id == N - 1) return 0;
	
	int& ans = dp[id][prev];
	
	if (ans == -1) {
		ans = INF;
		
		for (i = id; i < N; i++) {
			int prev_color = bf[road[id]];
			int curr_color = bf[road[i]];
			
			int dist = abs(i - id) * abs(i - id);
			
			if ((prev_color + 1) % 3 == curr_color) {
				ans = min(ans, dist + func(i, id, road));
			}
		}
	}
	
	return ans;
}

int ColorfulRoad::getMin(string road) {
	memset(dp, -1, sizeof(dp));
	
	bf['R'] = 0;
	bf['G'] = 1;
	bf['B'] = 2;
	
	int ans = func(0, 0, road);
	
	return ans == INF ? -1 : ans;
}

//Powered by [KawigiEdit] 2.0!
