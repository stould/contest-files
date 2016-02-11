#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class RoughStrings {
public:
	int minRoughness(string, int);
};

int RoughStrings::minRoughness(string s, int n) {
	vector<int> sum(26, 0);	
	int ans = INT_MAX;
	
	for (int i = 0; i < (int) s.size(); i++) {
		sum[s[i] - 'a'] += 1;
	}
	
	vector<int> vs;
	
	for (int i = 0; i < 26; i++) {
		if (sum[i] != 0) {
			vs.push_back(sum[i]);	
		}
	}
	
	sort(vs.begin(), vs.end());
	
	for (int i = 0; i <= 50; i++) {
		for (int j = 0; j <= i; j++) {			
			int op = 0;
				
			for (int k = 0; k < (int) vs.size(); k++) {
				if (vs[k] < j) {
					op += vs[k]; 
				} else if (vs[k] > i) {
					op += vs[k] - i;
				}
			}
			if (op <= n) ans = min(ans, i - j);
		}
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
