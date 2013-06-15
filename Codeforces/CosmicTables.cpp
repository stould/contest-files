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

const int MAXN = 1010;
int i, j, n, m, k, x, y, table[MAXN][MAXN], lastx[MAXN], lasty[MAXN];
char c;

int main(void) {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) REP(j, m) {
        scanf("%d", &table[i][j]);
        lastx[i] = i;
        lasty[j] = j;
    }
    REP(i, k) {
        scanf(" %c%d%d", &c, &x, &y);
        x -= 1; y -= 1;
        if(c == 'r') {
            swap(lastx[x], lastx[y]);
        } else if(c == 'c') {
            swap(lasty[x], lasty[y]);
        } else {
            printf("%d\n", table[lastx[x]][lasty[y]]);
        }
    }
    return 0;
}
