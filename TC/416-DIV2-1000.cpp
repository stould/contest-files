#include <bits/stdc++.h>

using namespace std;

class DancingCouples {
public:
	int countPairs(vector <string>, int);
};

vector<string> canDance;
int K;

int dp[11][(1 << 11)][11];

int func(int id_boy, int mask_girl, int couple) {
	if (id_boy == canDance.size()) {
		return couple == K;
	} else {
		int& ans = dp[id_boy][mask_girl][couple];
		
		if (ans == -1) {
			ans = func(id_boy + 1, mask_girl, couple);
			
			for (int i = 0; i < canDance[id_boy].size(); i++) {
				if (!(mask_girl & (1 << i)) && canDance[id_boy][i] == 'Y') {
					ans += func(id_boy + 1, mask_girl | (1 << i), couple + 1);
				}
			}
		}
		
		return ans;
	}
}

int DancingCouples::countPairs(vector<string> canDance, int K) {
	::canDance = canDance;
	::K = K;
	
	memset(dp, -1, sizeof(dp));
	
	return func(0, 0, 0);
}

//Powered by [KawigiEdit] 2.0!
