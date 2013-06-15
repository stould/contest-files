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

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

int i, n, k, p, t;

int main(void) {
    scanf("%d", &t);

    REP(i, t) {
        scanf("%d%d%d", &n, &k, &p);
        int pos = (k + p) % n;
        if(pos == 0) pos = n;
        printf("Case %d: %d\n", i + 1, pos);
    }
    return 0;
}

