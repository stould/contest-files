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

const int MAXN = 15;

int T, N;
int X[MAXN], Y[MAXN], Z[MAXN];
int a[2];
int dp[(1 << 15)][15][3];

pair<int, int> block(int id, int pos) {
	if (pos == 0) {
		a[0] = X[id];
		a[1] = Y[id];
	} else if (pos == 1) {
		a[0] = X[id];
		a[1] = Z[id];
	} else {
		a[0] = Y[id];
		a[1] = Z[id];
	}
	
	return make_pair(a[0], a[1]);
}

int getHeight(int id, int pos) {
	if (pos == 0) {
		return Z[id];
	} else if (pos == 1) {
		return Y[id];	
	} else {
		return X[id];	
	}
}

bool fit(int aid, int apos, int bid, int bpos) {
	pair<int, int> getA = block(aid, apos);
	pair<int, int> getB = block(bid, bpos);

	int la = getA.first;
	int ra = getA.second;
	
	int lb = getB.first;
	int rb = getB.second;

	return ((la >= lb && ra >= rb) || (la >= rb && ra >= lb));
}

int func(int mask, int id, int pos) {
	int& ans = dp[mask][id][pos];

	if (ans == -1) {
		ans = 0;
		
		for (int i = 0; i < N; i++) {
			if (!(mask & (1 << i))) {
				for (int j = 0; j < 3; j++) {
					if (fit(id, pos, i, j)) {
						chmax(ans, getHeight(i, j) + func(mask | (1 << i), i, j));
					}
				}
			}
		}
	}		
	
	return ans;
}

int main(void) {
    scanf("%d", &T);

	for ( ; T--; ) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &X[i], &Y[i], &Z[i]);
        }
		
		memset(dp, -1, sizeof(dp));

		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				chmax(ans, func((1 << i), i, j) + getHeight(i, j));
			}
		}

        printf("%d\n", ans);
    }
    return 0;
}
