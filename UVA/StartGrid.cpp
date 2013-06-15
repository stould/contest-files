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

int i, j, ans, n;

int index(int &x, vector<int> &v) {
    int i;
    REP(i, v.size()) if(v[i] == x) return i;
    return -1;
}

int main(void) {
    while(scanf("%d", &n) == 1) {
        vector<int> l(n), c(n);
        REP(i, n) scanf("%d", &l[i]);
        REP(i, n) scanf("%d", &c[i]);
        ans = 0;
        REP(i, n) {
            FOR(j, i + 1, n) {
                if(index(c[j], l) < index(c[i], l)) {
                    ans += 1;
                    swap(c[i], c[j]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

