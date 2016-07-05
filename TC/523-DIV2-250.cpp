/*aajjbb*/
#line 96 "AlphabetPath.cpp"
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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int vis[60][60] = {{0}};
char last;

void dfs(int i, int j, vector<string>& letterMaze) {
	vis[i][j] = 1;
	last = letterMaze[i][j];
	int k;
	REP(k, 4) {
		int ii = i + dx[k];
		int jj = j + dy[k];
		
		if(ii >= 0 && jj >= 0 && ii < letterMaze.size() && jj < letterMaze[0].size() && letterMaze[ii][jj] == letterMaze[i][j] + 1) {
			dfs(ii, jj, letterMaze);
		}
	}
}

struct AlphabetPath {
	string doesItExist(vector <string> letterMaze) {
		int i, j;
		REP(i, letterMaze.size()) {
			REP(j, letterMaze[0].size()) {
				if(letterMaze[i][j] == 'A') {
					dfs(i, j, letterMaze);
					return last == 'Z' ? "YES" : "NO";
				}
			}
		}	
		return "NO";
	}
};


// Powered by FileEdit
