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

int i, n, l, c, ans, ac;
string str;

int main(void) {
    while(scanf("%d%d%d", &n, &l, &c) == 3) {
        ans = 0, ac = 0;
        REP(i, n) {
            cin >> str;
            if(ac == 0) {
                ac = str.size();
            } else {
                if(ac + str.size() + 1 > c) {
                    ans += 1;
                    ac = str.size();
                } else {
                    ac += str.size() + 1;
                }
            }
        }
        if(ac != 0) ans += 1;
        printf("%d\n", (ans % l == 0) ? (ans / l) : ((ans / l) + 1));
    }
    return 0;
}

