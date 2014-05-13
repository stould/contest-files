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

class AntsMeet {
public:
	int countAnts(vector <int>, vector <int>, string);
};


int AntsMeet::countAnts(vector <int> x, vector <int> y, string direction) {
	int N = (int) x.size();

	int dx[N], dy[N];
	
	for (int i = 0; i < N; i++) {
		if (direction[i] == 'N') {
			dx[i] = 0;
			dy[i] = 1;			
		} else if (direction[i] == 'S') {
			dx[i] = 0;
			dy[i] = -1;
		} else if (direction[i] == 'W') {
			dx[i] = -1;
			dy[i] = 0;
		} else {		
			dx[i] = 1;
			dy[i] = 0;
		}
	}
	
	vector<bool> u(N, true);

	for (int t = 1; t <= 4000; t++) {	
		for (int i = 0; i < N; i++) {
			if (u[i]) {
				for (int j = i + 1; j < N; j++) {
					if (u[j]) {					
						int nx = 2 * x[i] + t * dx[i];
						int ny = 2 * y[i] + t * dy[i];
						int mx = 2 * x[j] + t * dx[j];
						int my = 2 * y[j] + t * dy[j];	
					
	
						if (nx == mx && ny == my) {						
							u[i] = u[j] = false;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		if (u[i]) {
			ans += 1;
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
