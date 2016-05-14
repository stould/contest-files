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

int i, n;

int main(void) {
    map<int, int> mp;
    map<int, int>::iterator it;
    scanf("%d", &n);
    REP(i, n) {
        int tmp;
        scanf("%d", &tmp);
        mp[tmp] += 1;
    }
    for(it = mp.begin(); it != mp.end(); it++) {
        printf("%d aparece %d vez(es)\n", it->first, it->second);
    }
    return 0;
}

