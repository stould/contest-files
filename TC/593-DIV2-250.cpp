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
#include <cstring>

using namespace std;

class RaiseThisBarn {
public:
	int calc(string);
};

int RaiseThisBarn::calc(string str) {
	int N = (int) str.size();
	int i;
	int buf[N];	memset(buf, 0, sizeof(buf));
	
	int ans = 0;
	
	for (i = 0; i < N; i++) {
		buf[i] += (str[i] == 'c');
		if (i > 0) {
			buf[i] += buf[i - 1];
		}
	}
	
	for (i = 1; i < N; i++) {
		int a = buf[i - 1];
		int b = buf[N - 1] - buf[i - 1];
		
		cout << a << " " << b << "\n";
		
		if (a == b) ans += 1;
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
