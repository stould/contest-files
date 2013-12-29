/*aajjbb*/
#line 104 "Painting.cpp"
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

struct Painting {
	int largestBrush(vector <string> picture) {
		int i, j, k, l, x, N = picture.size(), M = picture[0].size(), memo[N][M];
		
		for(x = min(N, M); x >= 1; x--) {
			int can = 1;
			memset(memo, 0, sizeof(memo));
			for(i = 0; i <= N - x; i++) {
				for(j = 0; j <= M - x; j++) {
					if(picture[i][j] == 'B') {
						int all_black = 1;
						for(k = 0; k < x; k++) {
							for(l = 0; l < x; l++) {
								if(picture[i+k][j+l] == 'W') all_black = 0;
							}
						}
						if(all_black) {
							for(k = 0; k < x; k++) {
								for(l = 0; l < x; l++) {
									memo[i+k][j+l] = 1;
								}
							}							
						}
					}
				}
			}
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(picture[i][j] == 'B' && memo[i][j] == 0) can = 0;
				}
			}
			if(can) return x;
		}
		return 1;
	}
};


// Powered by FileEdit