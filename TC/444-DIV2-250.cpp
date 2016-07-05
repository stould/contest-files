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
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
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

using namespace std;

typedef long long ll;
typedef long double ld;

struct FourBlocksEasy {
	int maxScore(vector <string> grid) {
		int i, j, outcome = 0, M = (int) grid[0].size();
		
		for (j = 0; j + 1 < M; j++) {
			if (grid[0][j] == '.' && grid[0][j+1] == '.' && grid[1][j] == '.' && grid[1][j+1] == '.') {
				outcome += 16;
				grid[0][j] = grid[0][j+1] = grid[1][j] = grid[1][j+1] = '4';
			}
		}
		
		for (i = 0; i < 2; i++) {
			for (j = 0; j < M; j++) {
				if (grid[i][j] != '4') outcome += 1;
			}
		}
		
		return outcome;		
	}
};

// Powered by FileEdit
