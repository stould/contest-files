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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int N, M;

int func(int a, int b) {
    int ans = 0;

    FOR(i, a, b+1) {
        int x = i, len = 0;
		int mask = 0, ok = 1;
        while(x > 0) {
			int d = (1 << (x % 10));
			if (mask & d) {
				ok = 0;
				break;
			}
			mask |= d;
            x /= 10;
        }
        if(ok) ans += 1;
    }

    return ans;
}

int main(void) {
    while(2 == scanf("%d%d", &N, &M)) {
        printf("%d\n", func(N, M));
    }
    return 0;
}

