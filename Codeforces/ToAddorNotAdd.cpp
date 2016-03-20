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

int i, j, n, k, v[100010];

int main(void) {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        scanf("%d", &v[i]);
    }
    sort(v, v + n);
    ll num = 0LL, t = 0LL;
    for(i = n - 1; i >= 0; i--) {
        ll diff = 0LL, ok = 1LL, ch = k;
        for(j = i - 1; j >= 0; j--) {
            if(v[i] - v[j] > ch) break;
            ch -= (v[i] - v[j]);
            ok += 1;
        }
        if(ok >= t) {
            num = v[i];
            t = ok;
        }
    }
    printf("%I64d %I64d\n", t, num);
    return 0;
}

