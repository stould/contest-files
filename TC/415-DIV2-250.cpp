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

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

struct CollectingUsualPostmarks {
	int numberOfPostmarks(vector <int> prices, vector <int> have) {
		vector<pair<int, int> > vp;
		
		REP(i, prices.size()) vp.push_back(make_pair(i, prices[i]));
		
		sort(vp.begin(), vp.end(), cmp);
	
		int money = 0, ans = 0;
	
		REP(i, vp.size()) {
			if(find(have.begin(), have.end(), vp[i].first) != have.end()) {
				money += vp[i].second;
			}
		}
		
		for(int i = vp.size() - 1; i >= 0; i--) {
			if(money - vp[i].second >= 0) {
				money -= vp[i].second;
				ans += 1;
			}
		}	
			
		return ans;
	}
};

// Powered by FileEdit
