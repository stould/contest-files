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

int i, n, k, p[300];

int main(void) {
    scanf("%d%d", &n, &k);
    REP(i, 2*n+1) {
        scanf("%d", &p[i]);
    }
    REP(i, 2*n+1) if(i > 0) {
        if(k > 0 && i == 2*n && p[i] - 1 >= 0) {
            p[i] -= 1;
            k -= 1;
        } else if(k > 0 && i & 1 != 0 && i - 1 >= 0 && i + 1 <= 2*n) {
            if(p[i] - 1 > p[i - 1] && p[i] - 1 > p[i + 1]) {
                p[i] -= 1;
                k -= 1;
            }
        }
        if(k == 0) break;
    }
    REP(i, 2*n+1) {
        printf("%d ", p[i]);
    } printf("\n");
    return 0;
}

