#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

Int A, B;
/*
0  - 0000
1  - 0001
2  - 0010
3  - 0011
4  - 0100
5  - 0101
6  - 0110
7  - 0111
8  - 1000
9  - 1001
10 - 1010
11 - 1011
12 - 1100
13 - 1101
14 - 1110
15 - 1111

*/
Int func(Int x) {
    Int ans = 0LL;
    Int bits = 1LL;
    Int range = 2LL;

    int i;
    Int len = (Int) floor(log10(x) / log10(2)) + 1;

    for (i = 0; i < len; i++) {
        if (x >= range) {
            if (x % range == 0) {
                ans += (Int) (x / range) * bits;
            } else {
                Int md = x % range + 1;
                Int div = floor(x / range);

                ans += div * bits + max(0LL, md - range / 2LL);
            }
        } else {
                Int c_range = range - (range - x) + 1;
                ans += max(0LL, c_range - range / 2LL);
        }

        bits *= 2LL;
        range *= 2LL;
    }

    return ans;
}



int main(void) {
    for ( ; cin >> A >> B; ) {
        cout << func(B) - func(A - 1) << "\n";
    }

    return 0;
}

