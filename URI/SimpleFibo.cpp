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

const double PI = 3.14159;
ll i, x, ans = 1, a = 0, b = 1, c;

int main(void) {
    scanf("%lld", &x);
    REP(i, x) {
        if(i == 0) { printf("%lld ", a); continue; }
        if(i == 1) { printf("%lld ", b); continue; }
        c = a + b;
        a = b; b = c;
        if(i == x - 1) printf("%lld\n", c);
        else printf("%lld ", c);
    }
    return 0;
}







