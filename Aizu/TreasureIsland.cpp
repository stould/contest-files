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


int a, b, i, n, ok, sum;

int main(void) {
    while(scanf("%d", &n) && n != 0) {
        vector<pair<int, int> > vp(n);
        sum = 0; ok = 1;
        REP(i, n) {
            scanf("%d%d", &vp[i].second, &vp[i].first);
        }
        sort(vp.begin(), vp.end());
        REP(i, n) {
            sum += vp[i].second;
            if(sum > vp[i].first) ok = 0;
        }
        if(ok == 1) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}

