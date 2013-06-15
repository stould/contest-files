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

int n, c, k, i, j, tmp;

int main(void) {
    for( ; scanf("%d%d%d", &n, &c, &k) == 3 && !(n == 0 && c == 0 && k == 0); ) {
        map<int, int> mp;
        map<int, int>::iterator it;
        int m = 1000000000;
        FOR(i, 1, k+1) mp[i] = 0;
        REP(i, n) {
            REP(j, c) {
                scanf("%d", &tmp);
                mp[tmp] += 1;
            }
        }
        it = mp.begin();
        for( ; it != mp.end(); it++) {
            m = min(m, it->second);
        }
        it = mp.begin();
        for( ; it != mp.end(); it++) if(it->second == m) {
            printf("%d ", it->first);
        }
        puts("");
    }
    return 0;
}



