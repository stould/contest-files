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

ll b, p, m;

ll poq(ll b, ll p, ll m){
    if(p == 0) {
        return 1;
    } else if(p % 2 == 0) {
        return ( (poq(b, (p / 2), m) ) * (poq(b, (p/2), m) ) ) % m;
    } else {
        return( (b % m) * poq(b, p - 1, m) ) % m;
    }
}

int main(void) {
    while(scanf("%lld%lld%lld", &b, &p, &m) == 3) {
        printf("%lld\n", poq(b, p, m));
    }    return 0;
}


