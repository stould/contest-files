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

set<int> mem;

int rev(int x) {
	int ans = 0;
	
	while(x > 0) {
		ans = ans * 10 + (x % 10);
		x /= 10;
	}
	
	return ans;
}

int bfs(int A, int B) {
	queue<pair<int, int> > q; q.push(make_pair(A, 0)); mem.insert(A);
	
	while(!q.empty()) {
		int now = q.front().first;
		int len = q.front().second;
		
		q.pop();
		
		if(now == B) return len;
		
		int ot = rev(now), bt = (int) floor(now/10.0);
		
		if(!mem.count(ot)) {
			q.push(make_pair(ot, len + 1)); mem.insert(ot);
		}
		if(!mem.count(bt)) {
			q.push(make_pair(bt, len + 1)); mem.insert(bt);
		}
	}
	return -1;
}

struct TheNumberGameDiv2 {
	int minimumMoves(int A, int B) {
		return bfs(A, B);
	}
};

// Powered by FileEdit
