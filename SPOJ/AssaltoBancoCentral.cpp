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

#define rep(i, n) for(int (i) = 0; i < n; i++)
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

int T, M, D, now, mask[25], deg[25];

int main(void) {
    scanf("%d", &T);
    for( ; T--; ) {
        scanf("%d%d", &M, &D);

        rep(i, D) {
            scanf("%d", &deg[i]);
            mask[i] = 0;
            rep(j, deg[i]) {
                scanf("%d", &now);
                mask[i] |= (1 << now);
            }
        }

        int minimal = INT_MAX;

        rep(i, (1 << D)) {
            int all = 0;
            rep(j, D) if((i >> j) & 1) {
                all |= mask[j];
            }
            int count = __builtin_popcount(all);
            if(count >= M) minimal = min(minimal, __builtin_popcount(i));
        }

        if(minimal == INT_MAX) {
            puts("Desastre!");
        } else {
            printf("%d\n", minimal);
        }
    }
    return 0;
}
