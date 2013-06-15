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
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int i, n, h[6];

struct cube {
    int a, b, c, d, e, f;
    cube(int a, int b, int c, int d, int e, int f): a(a), b(b), c(c), d(d), e(e), f(f){}
    bool operator<(const cube& cb) const { return a < cb.a; }
    bool operator==(const cube& cb) const {
        return a == cb.a && b == cb.b && d == cb.d && e == cb.e && f == cb.f;
    }
};

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &n) == 1 && !(n == 0)) {
        set<cube> p;
        REP(i, n) {
            scanf("%d%d%d%d%d%d", &h[0], &h[1], &h[2], &h[3], &h[4], &h[5]);
            sort(h, h + 6);
            do {
                p.insert(cube(h[0], h[1], h[2], h[3], h[4], h[5]));
            } while(next_permutation(h, h + 6));
        }
        printf("%d\n", (int) p.size());
    }
    return 0;
}


