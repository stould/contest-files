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

#define MOD 1300031
#define MAXN 1000000

int a, b, n, dp[MAXN+10], v[MAXN+1];

int main(void) {
    scanf("%d", &n);
    REP(i,MAXN+1) v[i] = i;
    for(i = 0; i <= MAXN; i++) {
        for(j = 1; j <= MAXN; j++) {
            dp[j] += dp[j = v[i]] % MOD;
        }
    }
    REP(i, n) {
        scanf("%lld%lld", &a, &b);
        print
    }
    return 0;
}

