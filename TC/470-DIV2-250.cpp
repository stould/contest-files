#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

class LinearTravellingSalesman {
	public:
	int findMinimumDistance(vector <int> x, vector <int> y)  {
		sort(x.begin(), x.end()); sort(y.begin(), y.end());
		return abs(x[0] - x[x.size() - 1]) + abs(y[0] - y[y.size() - 1]);
	}
};

// Powered by FileEdit
