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

template<typename T> void chmin(T& a, T b) {
    a = (a > b) ? b : a;
}
template<typename T> void chmax(T& a, T b) {
    a = (a < b) ? b : a;
}
int in() {
    int x;
    scanf("%d", &x);
    return x;
}

using namespace std;

typedef long long Int;
typedef unsigned uint;

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for (; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg) {
        x = -x;
    }
}

const int MAXN = 100007;

int N;
int dp[MAXN];

int func(int x) {
    if (x <= 1) return 0;
    if (x <= 3) return 1;

    int& ans = dp[x];

    if (ans != -1) return ans;

    int rest = 0;

    if (x % 3 == 0) {
        rest = x / 3;
    } else if (x % 3 == 1) {
        rest = (x - 1) / 3 + 1;
    } else {
        rest = (x - 2) / 3 + 1 ;
    }

    ans = rest + func(rest);

    return ans;
}

int main(void) {
    memset(dp, -1, sizeof(dp));

    for ( ; ; ) {
        fastRead_int(N);

        if (N == 0) break;

        printf("%d\n", func(N));
    }

    return 0;
}
