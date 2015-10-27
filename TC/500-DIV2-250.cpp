#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SRMCards {
	public:
	int maxTurns(vector <int> cards) {
		sort(cards.begin(), cards.end());
		int ans = 0;
		for(; !cards.empty(); ) {
			int acc = 10, index = 0, ind_prev = -1, ind_next = -1;
			for(int j = 0; j < cards.size(); j++) {
				int check = 1;
				bool prev = false, next = false;
				if(j + 1 < cards.size() && cards[j + 1] - 1 == cards[j]) { check += 1; next = true; }
				if(j - 1 >= 0 && cards[j - 1] + 1 == cards[j]) { check += 1; prev = true; }
				if(check < acc) {
					if(prev) ind_prev = j - 1; else ind_prev = -1;
					if(next) ind_next = j + 1; else ind_next = -1;
					acc = check; index = cards[j];
				}
			}
			ans += 1;
			cards.erase(find(cards.begin(), cards.end(), index));
			if(ind_prev != -1) cards.erase(find(cards.begin(), cards.end(), index - 1));
			if(ind_next != -1) cards.erase(find(cards.begin(), cards.end(), index + 1));
		}
		return ans;		
	}
};


// Powered by FileEdit
