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

const int INF = 1000 * 1000 * 1000;

namespace FenwickTree {
	vector<int> t;
	int n;

	void init(int _n) {
    	n = _n;
	    t.assign (n, 0);
	}

	int sum(int r) {
	    int result = 0;
	    for(; r >= 0; r = ((r & (r +1)) - 1)) {
	        result += t[r];
	    }
	    return result;
	}

	void inc(int i, int delta) {
	    for(; i < n; i = (i | (i +1))) {
	        t[i] += delta;
	    }
	}

	int sum(int l, int r) {
	    return sum (r) - sum (l-1);
	}

	int getmin(int r) {
	    int result = INF;
	    for (; r >= 0; r = ((r & (r + 1)) - 1)) {
	    	result = min (result, t[r]);
	    }
	    return result;
	}

	void update(int i, int new_val) {
	    for (; i < n; i = (i | (i +1))) {
	        t[i] = new_val;
	    }
	}
}

int N, v;
ll ans = 0LL;

int main(void) {
    scanf("%d", &N);
    FenwickTree::init(N);
    REP(i, N) {
        scanf("%d", &v);
        ans += i - FenwickTree::sum(v);
        FenwickTree::inc(v, 1);
    }
    printf("%lld\n",ans);
    return 0;
}
