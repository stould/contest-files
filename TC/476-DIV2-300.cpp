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

struct MatrixShiftings {
	int minimumShifts(vector <string> matrix, int value) {
		int i, j, N = matrix.size(), M = matrix[0].size(), ans = INT_MAX;
		
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (matrix[i][j] - '0' == value) {
					int l = min(j, M - j);
					int u = min(i, N - i);					
	
					ans = min(ans, l + u);
				}
			}
		}
		
		return ans == INT_MAX ? -1 : ans;
	}
};


// Powered by FileEdit
