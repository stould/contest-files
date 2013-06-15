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

int i, n, ans, m[101100];

int main(void) {
    while(scanf("%d", &n) && n != 0) {
        REP(i, n) scanf("%d", &m[i]);
        ans = 0;
        REP(i, n) {
            int ac = m[i];
            int back = i - 1 < 0 ? m[n-1] : m[i-1];
            int next = i + 1 >= n ? m[0] : m[i+1];

            if((ac < back && ac < next) || (ac > back && ac > next)) {
                ans += 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

