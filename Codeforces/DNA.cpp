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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1000007;

int N, s[MAXN];
char str[MAXN];

int main(void) {
    for ( ; scanf("%d%s", &N, str) == 2; ) {
	int i;

	s[0] = 0;

	for (i = 0; i < N; i++) {
	    s[i] = (str[i] == 'B');

	    if (i > 0) {
		s[i] += s[i - 1];
	    }
	}

	int ans = s[N - 1];

	for (i = 0; i < N; i++) {
	    int curr = (i + 1) - s[i] + (s[N - 1] - (i > 0 ? s[i - 1] : 0));

	    chmin(ans, curr);
	}
    
	printf("%d\n", ans);
    }

    return 0;
}
