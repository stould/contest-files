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

using namespace std;

typedef long long ll;
typedef long double ld;

int in(void) { int x; scanf("%d", &x); return x; }

int N, M, dp[109][109];

int rec(int a, int b) {
    if(a < b || b < 0) return 0;
    if(a <= 1) return 1;
    if(a == b) return 1;

    if(dp[a][b] != -1) return dp[a][b];

    return dp[a][b] = (rec(a-1, b-1) + rec(a-1, b));
}

int main(void) {
    int i, j;
    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        memset(dp, -1, sizeof(dp));
        printf("%d things taken %d at a time is %d exactly.\n", N, M, rec(N, M));
    }
    return 0;
}
