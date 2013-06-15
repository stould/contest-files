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

int T;
ll L, H;

ll ct(ll n) {
    if(n == 1) return 1L;

    ll x = (ll) sqrt(n);
    ll counter = 0;

    for(ll i = 1L; i <= x; i++) {
        if(n % i == 0) {
            counter += 2L;
        }
    }
    if(x * x == n) counter -= 1L;
    return counter;
}

int main(void) {
    cin >> T;
    while(T--) {
        cin >> L >> H;
        ll ans = -1, count = 0;
        for(ll i = L; i <= H; i += 1L) {
            ll tmp = (ll) ct(i);
            if(tmp > count) {
                count = (ll) tmp;
                ans = i;
            }
        }
        cout << "Between " << L << " and " << H << ", " << ans << " has a maximum of " << count << " divisors." << endl;
    }
    return 0;
}

