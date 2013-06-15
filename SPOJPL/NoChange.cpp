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

int N, M, v[10], dp[10000009];

int main(void) {
    while(scanf("%d %d", &N, &M) == 2) {
        REP(i, M) scanf("%d", &v[i]);

		FOR(i, 1, M) v[i] += v[i-1];

		memset(dp, 0, sizeof(dp));

		dp[0] = 1;
		for(int i = M - 1;  i >= 0; i--) {
			for(int j = v[i]; j <= M; j++) {
				dp[j] |= dp[j - v[i]];
			}
		}
		if(dp[M]) printf("YES\n");
		else printf("NO\n");
    }
    return 0;
}
