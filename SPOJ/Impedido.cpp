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

int a, d, i, ans, att[20], def[20];

int main(void) {
    for( ; scanf("%d%d", &a, &d) == 2 && !(a == 0 && d == 0); ) {
        REP(i, a) scanf("%d", &att[i]);
        REP(i, d) scanf("%d", &def[i]);
        sort(def, def + d);
        sort(att, att + a);
        if(att[0] < def[1]) puts("Y");
        else puts("N");
    }
    return 0;
}


