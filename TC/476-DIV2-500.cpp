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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Badgers {
public:
	int feedMost(vector <int>, vector <int>, int);
};

int Badgers::feedMost(vector <int> hunger, vector <int> greed, int totalFood) {
	int ans = 0;
	int N = (int) hunger.size();
	int cost[N];
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			cost[j] = hunger[j] + ((i - 1) * greed[j]);
		}
		sort(cost, cost + N);
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += cost[j];
		}		
		if (sum <= totalFood) {
			ans = i;
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
