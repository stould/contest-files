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

class CheatingQuiz {
public:
	vector <int> howMany(string);
};

vector <int> CheatingQuiz::howMany(string answers) {
	int N = (int) answers.size();
	vector<int> ans, cnt(3, 0);
	
	for (char c: answers) {
		cnt[c - 'A'] += 1;
	}
	
	for (int i = 0; i < N; i++) {
		int us = 0;
		for (int j: cnt) {
			if (j > 0) us++;
		}
		ans.push_back(us);
		cnt[answers[i] - 'A'] -= 1;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
