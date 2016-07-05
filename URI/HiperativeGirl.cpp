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

const int MAXN = 107;
const int MOD = 100000000;

int N, M;

pair<int, int> p[MAXN];

int dp[MAXN][MAXN];
int us;
vector<int> path;

int func(int index, int last) {
    if (p[index].second == M) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
        return 1;
    }
	
    int ans = dp[index][last];
	
	ans = 0;
	
	for (int i = index + 1; i < N; i++) {
		if (p[i].first > p[index].first && p[i].first <= p[index].second && p[i].second > p[index].second  && (index == last || p[i].first > p[last].second)) {
			path.push_back(i);
			ans = (ans + func(i, index)) % MOD;
			path.pop_back();
		}
	}
	
    return ans;
}

int main(void) {
    for ( ; scanf("%d%d", &M, &N) == 2 && N + M != 0; ) {
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &p[i].first, &p[i].second);
        }
		
        sort(p, p + N);
		for (int i = 0; i < N; i++) {
			printf("%d => %d - %d\n", i, p[i].first, p[i].second);
		}
			
        memset(dp, -1, sizeof(dp));
		
        int ans = 0;

        for (int i = 0; i < N; i++) {
            if (p[i].first == 0) {
				path.push_back(i);
				ans += func(i, i);
				path.pop_back();
			}
            if (ans >= MOD) ans -= MOD;
        }

        printf("%d\n", ans);
    }
    return 0;
}
