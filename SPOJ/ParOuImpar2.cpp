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

int n, i, j, x[110], y[110], ans;

int main(void) {
    freopen("i.in", "r", stdin);
    for( ; scanf("%d", &n) == 1 && n != 0; ) {
        REP(i, n) scanf("%d", &x[i]);
        REP(i, n) scanf("%d", &y[i]);
        ans = 0;
        REP(i, n) {
            REP(j, n) {
                if((x[i] + y[j]) % 2 != 0 && (x[i] != -1 && y[j] != -1)) {
                    x[i] = y[j] = -1;
                }
            }
        }
        REP(i, n) if(x[i] != -1) ans += 1;
        printf("%d\n", ans);
    }
    return 0;
}

