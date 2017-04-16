#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define REP(i, n) for(i = 0; i < n; i++)

using namespace std;

typedef long long ll;

const double INF = 1e10;
ll n, k;

double max(double a, double b) { return a > b ? a : b; }
double min(double a, double b) { return a > b ? b : a; }

ll check(ll r) {
  ll c = 1;
  ll s = c;
  for (ll p = 1; p <= k; p++) {
    c *= r - p + 1;
    c /= p;
    s += c;
    if (s > n) break;
  }
  return s;
}


int main(void) {
    scanf("%lld%lld", &n, &k);
    ll ans = 0;
    ll low = 0, high = n, mid;
    while(high - low > 1) {
        mid = low + (high - low) / 2;
        if(check(mid) <= n) {
            low = mid;
        } else {
            high = mid;
        }
    }
    printf("%lld\n", low+1);
    return 0;
}

