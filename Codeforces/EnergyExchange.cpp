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

int i, n, k, acc[10010];

double func(double x) {
	double H = 0, L = 0;
	for(int i = 0; i < n; i++)
		if(acc[i] > x) H += 0.0 + acc[i] - x;
		else L += x - acc[i];
	return .01 * (100-k) * H >= L;
}

int main(void) {
    cin >> n >> k;
    REP(i, n) cin >> acc[i];

    double low = 0, high = 100010, mid, sum;

    for(int x = 0; x < 50; x++) {
        mid = (low + high) / 2;
        if(ok(mid)) {

        } else {

        }
    }

    printf("%.8lf\n", low);
    return 0;
}

