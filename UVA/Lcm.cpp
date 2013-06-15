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

ll v;

ll gcd(ll a, ll b) {
    if(!b) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(void) {
    while(scanf("%lld", &v)) {
        if(v == 0) break;
        ll last = v;
        for(ll i = 2L; i <= v; i++) {
            last = lcm(last, i);
            while(last % 10 == 0) last /= 10;
        }
        printf("%lld\n", last % 10);
    }
    return 0;
}



