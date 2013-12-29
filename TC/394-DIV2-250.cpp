#line 116 "MountainWalk.cpp"
/*
 aajjbb
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int vis[60][60] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0,-1,  0, 1};
int ans = 0;

void dfs(int i, int j, vector<string> areaMap, int heightDifference) {
	ans += 1;
	vis[i][j] = 1;
	int x;
	int ni = 0, nj = 0;
	REV(x, 3, -1) {
		int ii = i + dx[x];
		int jj = j + dy[x];		
		if(ii >= 0 && ii < areaMap.size() && jj >= 0 && jj < areaMap[0].size() && abs(areaMap[i][j]-areaMap[ii][jj]) <= heightDifference && !vis[ii][jj]) {
			ni = ii;
			nj = jj;
		}
	}
	if(ni == 0 && nj == 0) return;
	dfs(ni, nj, areaMap, heightDifference);
}

struct MountainWalk {
	int cellsVisited(vector <string> areaMap, int heightDifference) {
		dfs(0, 0, areaMap, heightDifference);
		return ans;
	}
};


// Powered by FileEdit