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
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

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

int i, j, x, y, ans_i = 0, ans_j = 0, NA, MA, NB, MB;
char a[60][60];
char b[60][60];

int main(void) {
    scanf("%d%d", &NA, &NB);
    REP(i, NA) {
        scanf("%s", a[i]);
    }
    scanf("%d%d", &MA, &MB);
    REP(i, MA) {
        scanf("%s", b[i]);
    }
    int mx = -1;
    FOR(x, -60, 61) FOR(y, -60, 61) {
        int actual = 0;
        REP(i, NA) REP(j, NB) {
            if(i + x < MA && j + y < MB && i + x >= 0 && j + y >= 0) {
                actual += (a[i][j] - '0') * (b[i+x][j+y] - '0');
            }
        }
        if(actual >= mx) {
            mx = actual;
            ans_i = x;
            ans_j = y;
        }
    }
    printf("%d %d\n", ans_i, ans_j);
    return 0;
}
