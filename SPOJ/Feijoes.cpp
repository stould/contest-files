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

typedef long long Int;
typedef long double ld;

const Int INF = 1000100100101001010LL;

Int goal, ans;
int T, cnt;

void rec(Int curr, int mask, int id, Int base) {
	if (curr > goal) {

	}
}

int main(void) {
    scanf("%d", &T);

    for( ; T--; ) {
        scanf("%ll%d", &goal, &cnt);
		int L = len(goal);
        for(int i = 0; i < (1 << 10); i++) if(__builtin_popcount(i) == cnt) {
            int pre_mask = 0;
            for(int j = 0; j < 10; j++) {
				if ((1 << j) & i) {
					pre_mask |= (1 << j);
				}
			}


        }
    }

    return 0;
}
