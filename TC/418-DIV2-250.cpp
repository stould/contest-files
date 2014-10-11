#include <bits/stdc++.h>

using namespace std;

class Towers {
public:
	int attack(int, int, int, int);
};

int Towers::attack(int myUnits, int hpT, int attackT, int numT) {
	vector<int> life(numT, hpT);
	
	for (int round = 1; myUnits > 0; round++) {		
		sort(life.begin(), life.end());
		
		int attack = myUnits;
		
		for (int i = 0; i < (int) life.size(); i++) {
			if (life[i] <= attack) {
				attack -= life[i];
				life[i] = 0;	
			} else {
				life[i] -= attack;
				attack = 0;
				break;
			}
		}
		
		vector<int> cpy;
		
		for (int i = 0; i < life.size(); i++) {
			if (life[i] != 0) {
				cpy.push_back(life[i]);
			}
		}
		
		life = cpy;
		myUnits -= attackT * life.size();
		
		if (life.empty()) return round;
	}
	
	return -1;
}

//Powered by [KawigiEdit] 2.0!
