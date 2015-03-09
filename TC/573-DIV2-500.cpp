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

int mine;

struct TeamContestEasy {
	int worstRank(vector <int> s) {
		mine = (s[0] + s[1] + s[2]) - min(s[0], min(s[1], s[2]));
		
		s.erase(s.begin(), s.begin() + 3);
		
		sort(s.begin(), s.end());
		
		s.erase(s.begin(), s.begin() + (s.size() / 3));
		
		sort(s.rbegin(), s.rend());
		
		int ans = 0, low = 0, high = s.size() - 1;
		
		for( ; low < high; ) {
			if(s[low] + s[high] > mine) {
				ans += 1;
				low += 1;
			}
			high -= 1;
		}		
		
		return ans + 1;		
	}
};

// Powered by FileEdit
