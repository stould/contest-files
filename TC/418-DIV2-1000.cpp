#include <bits/stdc++.h>

using namespace std;

class BarracksEasy {
public:
	int attack(int, int, int);
};

const int INF = INT_MAX / 3;
int dp[60][60][130];

int func(int myUnits, int barHp, int enemyUnits, int unitsPerRound) {		
	if (barHp <= 0 && enemyUnits <= 0) {
		return 0;
	} else if (myUnits <= 0) {
		return INF;
	} else {
		int& ans = dp[myUnits][barHp][enemyUnits];
		
		if (ans == -1) {
			ans = INF;			
			
			//using i soldier to attack the barrack
			for (int i = myUnits; i >= 0; i--) {						
				int nextUnits = max(0, myUnits - (enemyUnits - (myUnits - i)));
				int nextBarHp = max(0, barHp - i);
				int nextEnemies = max(0, nextBarHp > 0 ? (enemyUnits + unitsPerRound - (myUnits - i)) : enemyUnits - (myUnits - i));
				
				nextEnemies = min(nextEnemies, 120);
				
				if (nextUnits <= myUnits) {				
					int next = 1 + func(nextUnits, nextBarHp, nextEnemies, unitsPerRound);
					ans = min(ans, next);				
				}
			}
		}
		
		return ans;
	}
}

int BarracksEasy::attack(int myUnits, int barHp, int unitsPerRound) {
	memset(dp, -1, sizeof(dp));
	
	int ans = func(myUnits, barHp, 0, unitsPerRound);
	
	return ans >= INF ? -1 : ans;
}

//Powered by [KawigiEdit] 2.0!
