/* aajjbb */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int func(vector<int>& Y, int x) {
	int i, ans = 0;
	
	for (i = 1; i < Y.size(); i++) if (Y[i] == Y[i-1] && Y[i] == x) return -1;
	
	for (i = 1; i < Y.size(); i++) {
		if ((Y[i] >= x && Y[i-1] <= x) || (Y[i] <= x && Y[i-1] >= x)) {
			ans += 1;
			if (Y[i] == x) i += 1;
		}
	}
	return ans;
}

struct PiecewiseLinearFunctionDiv2 {
	vector <int> countSolutions(vector <int> Y, vector <int> query) {
		int i, N = query.size();
		vector<int> ans;
		
		for (i = 0; i < N; i++) {
			int cnt = func(Y, query[i]);
			
			ans.push_back(cnt);
		}
		
		return ans;		
	}
};

// Powered by FileEdit
