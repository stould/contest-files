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

int i, n, ans = 0, v[100010], v2[100010];

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &v[i]);
        v2[i] = v[i];
    }
    sort(v2, v2 + n);
    REP(i, n) {
        if(v[i] != v2[i]) ans += 1;
    }
    if(ans <= 2) puts("YES");
    else puts("NO");
    return 0;
}


