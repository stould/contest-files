/*
  aajjbb
*/
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

struct CityMap {
	string getLegend(vector <string> cityMap, vector <int> POIs) {
		int i, j, N = cityMap.size(), M = cityMap[0].size();
		string ans = "";
		
		int cnt[30] = {0};
		
		REP(i, N) REP(j, M) if(cityMap[i][j] != '.') cnt[cityMap[i][j]-'A'] += 1;
		
		REP(i, POIs.size()) {
			REP(j, 27) if(cnt[j] == POIs[i]) {
				ans += 'A' + j; break;
			}
		}
		
		return ans;	
	}
};


// Powered by FileEdit
