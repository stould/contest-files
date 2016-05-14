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

int i, n, x;

ll func(int x) {
    ll ans = 0LL, i, a = sqrt(x);
    for(i = 1; i <= a; i += 1) {
        if(x % i == 0) {
            ans += i;
            ll k = x / i;
            if(k != i) ans += k;
        }
    }
    return ans-x;
}

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &x);
        printf("%lld\n", func(x));
    }
    return 0;
}
