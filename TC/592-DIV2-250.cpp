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

class LittleElephantAndBooks {
public:
	int getNumber(vector <int>, int);
};

int LittleElephantAndBooks::getNumber(vector <int> pages, int number) {
	int i;
	int ansA = 0, ansB = 0;
	int N = pages.size();
	
	sort (pages.begin(), pages.end());	
	
	for (i = 1; i < N && i < number + 1; i++) {
		ansA += pages[i];
	}
	
	for (i = 0; i < N && i < number - 1; i++) {
		ansB += pages[i];
	}
	ansB += pages[i+1];
	
	return min(ansA, ansB);
}

//Powered by [KawigiEdit] 2.0!
