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

class TheMoviesLevelTwoDivTwo {
public:
	vector <int> find(vector <int>, vector <int>);
};

vector <int> TheMoviesLevelTwoDivTwo::find(vector <int> length, vector <int> scary) {
	int N = (int) length.size();
	int ans_seen = -1;
	vector<int> pre(N), ans(N);
	
	for (int i = 0; i < N; i++) {
		pre[i] = i;
	}
	
	do {
		int seen = 0;
		int sc = 74;
		
		for (int i = 0; i < N; i++) {						
			if (sc - scary[pre[i]] >= 0 && sc + 47 >= length[pre[i]]) {
				sc += 47 - length[pre[i]];
			} else {
				break;
			}			
			seen += 1;
		}
		if (seen > ans_seen) {
			ans_seen = seen;
			ans = pre;
		}
	} while (next_permutation(pre.begin(), pre.end()));
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
