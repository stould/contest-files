#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

struct lady {
    int b, i, r;
    lady(){ b = i = r = 0; }
    lady(int b, int i, int r): b(b), i(i), r(r){}

    bool operator<(const lady& l) const {
        return max(b, max(i, r)) < max(l.b, max(l.i, l.r));
    }

    bool operator>(const lady& l) const {
        return (b+i+r) > (l.b + l.i + l.r);
    }
};

int cmp(lady a, lady b) {
    return a.b < b.b && a.i < b.i && a.r < b.r;
}

int i, x, n;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &n);
    set<lady> st;
    vector<lady> vc(n);
    lady bigger;
    REP(x, 3) {
        REP(i, n) {
            if(x == 0) { scanf("%d", &vc[i].b);
            } else if(x == 1) { scanf("%d", &vc[i].i);
            } else if(x == 2) {
                scanf("%d", &vc[i].r);
                if(vc[i] > bigger) bigger = vc[i];
            }
        }
    }
   // printf("%d %d %d\n", bigger.b, bigger.i, bigger.r);
    int ans = 0;
    REP(i, n) {
        if(cmp(vc[i], bigger)) ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}

