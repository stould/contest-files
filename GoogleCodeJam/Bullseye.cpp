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

int T, r, t;

int main(void) {
    int i, x, cnt;
    scanf("%d", &T);

    for ( ; T--; ) {
        scanf("%d%d", &r, &t);

        for (x = 1; x <= 100; x++) {
            double acc = 0.0;
            for (i = r + 1, cnt = 0; cnt < x; i += 2, cnt += 1) {
                acc += (i * acos(-1.0)) - ((i - 1) * acos(-1.0));
            }
            if(acc <= t) {
                printf("%d\n", x);
            }
        }
    }
    return 0;
}
