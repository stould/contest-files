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

int a, b, i, j, n, x0, track[1010];

int main(void) {
    scanf("%d%d", &n, &x0);
    memset(track, 0, sizeof(track));
    REP(i, n) {
        scanf("%d%d", &a, &b); if(a > b) swap(a, b);
        FOR(j, a, b+1) track[j] += 1;
    }
    int ans = 100000000;
    REP(i, 1001) if(track[i] == n) ans = min(ans, abs(x0 - i));
    if(ans == 100000000) puts("-1");
    else printf("%d\n", ans);
    return 0;
}


