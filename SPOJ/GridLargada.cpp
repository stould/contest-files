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

#define MAXN 10100

int i, num, pos, n, used[MAXN];

int main(void) {
    while(scanf("%d", &n) == 1 && n != 0) {
        memset(used, -1, sizeof(used));
        bool ok = true;
        REP(i, n) {
            scanf("%d%d", &num, &pos);
            if(i + pos < 0 || i + pos > n || used[i + pos] != -1) {
                ok = false;
            } else {
                used[i + pos] = num;
            }
        }
        int count = 0;
        REP(i, n) if(used[i] != -1) count += 1;
        if(!ok || count != n) {
            puts("-1");
        } else {
            REP(i, n) {
                if(used[i] != -1) {
                    printf("%d ", used[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

