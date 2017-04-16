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
#define FOR(i, a, n) for((i) = (a); (i) <= (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int i, j, n, k, l = -1, r = -1, len, v[100010];

int main(void) {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        scanf("%d", &v[i]);
        set<int> s;
        s.insert(v[i]);
        for(j = i - 1; j >= 0; j--) {
            s.insert(v[j]);
            if(s.size() == k) {
                l = j + 1, r = i + 1; len = i - j + 1;
            }
            if(s.size() > k) break;
        }
    }
    printf("%d %d\n", l, r);

    return 0;
}

