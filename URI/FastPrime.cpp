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

bool isPrime(int x) {
    if(x <= 1) return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for(int i = 3; i <= sqrt(x); i += 2) {
        if(x % i == 0) return false;
    }
    return true;
}

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &x);
        puts(isPrime(x) ? "Prime" : "Not Prime");
    }
    return 0;
}

