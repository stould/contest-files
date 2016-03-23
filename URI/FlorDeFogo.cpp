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

int ra, rb, xa, xb, ya, yb;

int main(void) {
    while(scanf("%d%d%d%d%d%d", &ra, &xa, &ya, &rb, &xb, &yb) == 6) {
        if((hypot(xa - xb, ya - yb) + rb) <= ra) {
            printf("RICO\n");
        } else {
            printf("MORTO\n");
        }
    }
    return 0;
}

